/** tImage.cpp   ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library OpenCV 2.4.6
**
***********************************/

#include "tImage.h"


//namespace
using namespace cv;
using namespace std;


///variables
int const tImage::maxAT_BINARY_value = 1000;
//contourDrawing variables
Scalar contourColor = Scalar(0, 0, 255);

///constructeur
tImage::tImage(void)
{
}

///destructeur
tImage::~tImage(void)
{
}


/**
* @méthode ThresholdGlobal() : Méthode de seuillage global.
**/
Mat tImage::ThresholdGlobal( Mat src, int thresholdValue, int maxBinaryValue )
{
	Mat dst;
	//src is already a gray level image
	threshold( src, dst, thresholdValue, maxBinaryValue, CV_THRESH_BINARY );
	return dst;
}


/**
* @méthode Morphology_Operations() : Éliminer les bruits et les petits objets.
**/
Mat tImage::Morphology_Operations( Mat src, char operation, int morphElem, int morphSize )
{
	Mat inter, dst;

	Mat element = getStructuringElement( morphElem, Size( 2*morphSize + 1, 2*morphSize+1 ), Point( morphSize, morphSize ) );
	/// Appliquer l'opération de morphologie.
	morphologyEx( src, dst, operation, element );
	//morphologyEx( inter, dst, MORPH_OPEN, element );
	//morphologyEx( inter, dst, MORPH_CLOSE, element );

	return dst;
}


///**
//* @méthode shouldIInvetIt() : méthode pour déterminer s’il faut inverser l'image.
//* La méthode est utilisée pour détecter si le papier bioactif est blanc ou noir.
//**/
bool tImage::shouldIInvertIt( Mat src )
{
	float non_Zero = countNonZero(src);
	float allPixels = src.size().area();
	float percentage = ( non_Zero / allPixels ) * 100;
	if ( percentage > 0.55 ) return false;
	else return true;	
}


///**
//* @method adaptive_Threshold() : Méthode de seuillage adaptatif local
//**/
Mat tImage::adaptive_Threshold( Mat src, int blockSize, int C )
{
	//blockSize doit être un nombre impair à partir de 3: 3, 5, 7 ...
	Mat dst;
	adaptiveThreshold( src, dst, maxAT_BINARY_value, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, C );

	return dst;
}


///**
//* @méthode boundingBox() : Méthode pour trouver le plus grand contour.
//**/
pair <vector<vector<Point> >, int> tImage::boundingBox( Mat src, char thresholding_Type )
{
	//variables
	Mat threshold_output, src_gray;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	int threshVal = 100;
	int largest_area = 0, largest_contour_index = 0;

	//functionality
	/// Permet de lisser une image.
	blur( src_gray, src_gray, Size(9,9) );
	/// Détecter les bords à l'aide de seuillage.
	threshold( src, threshold_output, threshVal, 255, thresholding_Type );
	/// Trouver les contours.
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	/// Contours approximatifs en polygones.
	vector<vector<Point> > contours_poly( contours.size() );
	/// La boîte englobante.
	vector<Rect> boundRect( contours.size() );
	/// Trouver le plus grand contour
	for( int i = 0; i < contours.size(); i++ ) //iterate through each contour.
	{
		// Trouver l'aire de contour
		double a = contourArea( contours[i], false );
        if( a > largest_area )
		{
			largest_area = a;
			// Stocker l'index du plus grand contour.
			largest_contour_index = i;
			approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
			boundRect[i] = boundingRect( Mat(contours_poly[i]) );// Trouver le rectangle de délimitation pour le plus grand contour.
		}
	}
	// Retourner l'ensemble de points de plus grand contour et l'index de ce contour.
	return make_pair( contours, largest_contour_index );
}


///**
//* @method contourDrawing() : Méthode pour dessiner le contour.
//**/
Mat tImage::contourDrawing( Mat src, vector<vector<Point> > contours, int contour_index , Scalar zCountourColor, int thickness )
{
	Mat dst = src.clone();
	drawContours( dst, contours, contour_index, zCountourColor, thickness, 8, vector<Vec4i>(), 0, Point() );
	
	return dst;
}


///**
//* @méthode contour_area() : Méthode qui retourne le nombre de pixels non nuls à l'intérieur d'un contour donné.
//**/
float tImage::contour_area( vector<vector<Point> > contours, int index )
{
	float pArea;
	pArea = contourArea(contours[index]);
	return pArea;
}


///**
//* @method calculateAreaInMmSquare() : Calculer l’aire à l’intérieur du contour en unité carré.
//**/
float tImage::calculateAreaInMmSquare(Mat imgRef, float zoneDeLyse, int radius)
{
	float non_Zero;
	float onePixel;
	float zoneDeLyseEnMmCarre;
	non_Zero = countNonZero(imgRef);
	if(non_Zero != 0)
	{
		onePixel = ( ( PI * radius * radius ) / non_Zero );
		zoneDeLyseEnMmCarre = onePixel * zoneDeLyse;
	}

	return zoneDeLyseEnMmCarre;
}


/////**
////* @method addBorders
////**/
//Mat tImage::addBorders( Mat src )
//{
//	//variables
//	Mat dst;
//	int top, bottom, left, right;
//	Scalar bordersColor;
//
//	//initialize arguments for the filter (5% the size of src)
//	top = (int) (0.05*src.rows); bottom = (int) (0.05*src.rows);
//	left = (int) (0.05*src.cols); right = (int) (0.05*src.cols);
//	bordersColor = Scalar(0, 0, 0);
//	// add borders
//	copyMakeBorder( src, dst, top, bottom, left, right, BORDER_CONSTANT, bordersColor );
//
//	return dst;
//}


///**
//* @method traitementImage
//**/
pair<Mat, float> tImage::traitementImage(Mat imgSrc, int rayon)
{
	//variables 
	Mat imgGray, imgTG, imgMOc, imgInverted, imgAT, imgMOt, imgDst;
	//ThreshholdGlobal() - valeur de la variable.
	int const maxTG_BINARY_value = 255;
	int threshold_value = 170;
	//Morphology_Operations() - les valeurs des variables.
	// 1 est un élément de structuration elliptique.
	// 0 est un élément de structuration rectangulaire.
	// and 2 est un élément de structuration cross-shaped.
	int morph_elem = 1;
	int morph_size = 12; // kernel size
	//adaptive_Threshold() - les valeurs des variables.
	int block_Size = 999, cst = 5;
	
	/// Crée une copie complète de la matrice.
	/// on va utiliser dessiner le contour sur ce clone et afficher l'image avec contour.
	Mat imgClone = imgSrc.clone();

	/// Convertir l'image en niveau de gris
	cvtColor( imgSrc, imgGray, CV_RGB2GRAY );

	/// ThresholdGlobal() : méthode de seuillage global
	imgTG = ThresholdGlobal( imgGray, threshold_value, maxTG_BINARY_value );

	/// Morphology_Operations() : méthode pour éliminer les bruits et les petits objets.
	imgMOc = Morphology_Operations( imgTG, MORPH_OPEN, morph_elem, morph_size );
	
	/// Inverser l'image, si nécessaire.
	bool invert = shouldIInvertIt( imgMOc );
	if ( invert == true ) 
	{
		bitwise_not( imgGray, imgInverted );
		imgTG = ThresholdGlobal( imgInverted, threshold_value, maxTG_BINARY_value );
		imgMOc = Morphology_Operations( imgTG, MORPH_OPEN, morph_elem, morph_size );
		// Les étapes pour peindre le papier noir en blanc
		pair <vector<vector<Point> >, int> bounding_box_c;
		bounding_box_c = boundingBox( imgMOc, THRESH_BINARY );
		vector<vector<Point> > allContours_c = bounding_box_c.first;
		int largestContourIndex_c = bounding_box_c.second;
		/// remplacer l'ancienne valeur de imgSrc par la nouvelle valeur.
		imgSrc = contourDrawing( imgSrc, allContours_c, largestContourIndex_c, Scalar(255, 255, 255), -1 );
		/// Convertir l'image en niveau de gris
		cvtColor( imgSrc, imgGray, CV_RGB2GRAY );
	}

	/// adaptative_Threshold() : méthode de seuillage local adaptatif
	imgAT = adaptive_Threshold( imgGray, block_Size, cst );

	/// Morphology_Operations() : méthode pour éliminer les bruits et les petits objets.
	imgMOt = Morphology_Operations( imgAT, MORPH_CLOSE, morph_elem, morph_size );

	// imgMOt est une image d'un objet noir sur un fond blanc
	// on veut un objet blanc sur fond noir
	// Inverse chaque bit d'un tableau.
	bitwise_not( imgMOt, imgMOt );

	/// Trouver le plus grand contour.
	pair <vector<vector<Point> >, int> bounding_box;
	bounding_box = boundingBox( imgMOt, THRESH_BINARY );
	vector<vector<Point> > allContours = bounding_box.first;
	int largestContourIndex = bounding_box.second;

	/// Dessiner le contour le plus grand.
	imgDst = contourDrawing( imgClone, allContours, largestContourIndex, contourColor, 3 );

	/// Calculer le nombre de pixels à l'intérieur contour puis calculer l'aire en mm carré.
	float zone_de_lyse = contour_area( allContours, largestContourIndex );
	float area = calculateAreaInMmSquare(imgMOc, zone_de_lyse, rayon);

	return make_pair( imgDst, area );
}
