/****************************************************************************
** Meta object code from reading C++ file 'zlprojet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zlprojet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zlprojet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_zLProjet_t {
    QByteArrayData data[23];
    char stringdata[476];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_zLProjet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_zLProjet_t qt_meta_stringdata_zLProjet = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 26),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 36),
QT_MOC_LITERAL(4, 74, 27),
QT_MOC_LITERAL(5, 102, 34),
QT_MOC_LITERAL(6, 137, 33),
QT_MOC_LITERAL(7, 171, 47),
QT_MOC_LITERAL(8, 219, 24),
QT_MOC_LITERAL(9, 244, 26),
QT_MOC_LITERAL(10, 271, 20),
QT_MOC_LITERAL(11, 292, 20),
QT_MOC_LITERAL(12, 313, 22),
QT_MOC_LITERAL(13, 336, 26),
QT_MOC_LITERAL(14, 363, 4),
QT_MOC_LITERAL(15, 368, 10),
QT_MOC_LITERAL(16, 379, 9),
QT_MOC_LITERAL(17, 389, 9),
QT_MOC_LITERAL(18, 399, 18),
QT_MOC_LITERAL(19, 418, 13),
QT_MOC_LITERAL(20, 432, 13),
QT_MOC_LITERAL(21, 446, 11),
QT_MOC_LITERAL(22, 458, 16)
    },
    "zLProjet\0on_action_Ouvrir_triggered\0"
    "\0on_actionExporter_r_sultat_triggered\0"
    "on_action_Quitter_triggered\0"
    "on_action_Calcul_surface_triggered\0"
    "on_actionMettreAEchelle_triggered\0"
    "on_action_Effacer_la_liste_des_images_triggered\0"
    "on_actionAid_e_triggered\0"
    "on_action_propos_triggered\0"
    "on_btnOuvrir_clicked\0on_btnCalcul_clicked\0"
    "on_btnExporter_clicked\0"
    "on_comboBoxlsImg_activated\0open\0"
    "Mat2QImage\0cv::Mat3b\0labelSize\0"
    "addFileNameToTable\0calculSurface\0"
    "storeImgInDir\0deleteFiles\0exporterResultat\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zLProjet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08,
       3,    0,  115,    2, 0x08,
       4,    0,  116,    2, 0x08,
       5,    0,  117,    2, 0x08,
       6,    0,  118,    2, 0x08,
       7,    0,  119,    2, 0x08,
       8,    0,  120,    2, 0x08,
       9,    0,  121,    2, 0x08,
      10,    0,  122,    2, 0x08,
      11,    0,  123,    2, 0x08,
      12,    0,  124,    2, 0x08,
      13,    1,  125,    2, 0x08,
      14,    1,  128,    2, 0x08,
      15,    1,  131,    2, 0x08,
      17,    0,  134,    2, 0x08,
      18,    0,  135,    2, 0x08,
      19,    0,  136,    2, 0x08,
      20,    2,  137,    2, 0x08,
      21,    0,  142,    2, 0x08,
      22,    1,  143,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::QImage, 0x80000000 | 16,    2,
    QMetaType::QSize,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void zLProjet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zLProjet *_t = static_cast<zLProjet *>(_o);
        switch (_id) {
        case 0: _t->on_action_Ouvrir_triggered(); break;
        case 1: _t->on_actionExporter_r_sultat_triggered(); break;
        case 2: _t->on_action_Quitter_triggered(); break;
        case 3: _t->on_action_Calcul_surface_triggered(); break;
        case 4: _t->on_actionMettreAEchelle_triggered(); break;
        case 5: _t->on_action_Effacer_la_liste_des_images_triggered(); break;
        case 6: _t->on_actionAid_e_triggered(); break;
        case 7: _t->on_action_propos_triggered(); break;
        case 8: _t->on_btnOuvrir_clicked(); break;
        case 9: _t->on_btnCalcul_clicked(); break;
        case 10: _t->on_btnExporter_clicked(); break;
        case 11: _t->on_comboBoxlsImg_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->open((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 13: { QImage _r = _t->Mat2QImage((*reinterpret_cast< const cv::Mat3b(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 14: { QSize _r = _t->labelSize();
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = _r; }  break;
        case 15: _t->addFileNameToTable(); break;
        case 16: _t->calculSurface(); break;
        case 17: _t->storeImgInDir((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->deleteFiles(); break;
        case 19: _t->exporterResultat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject zLProjet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_zLProjet.data,
      qt_meta_data_zLProjet,  qt_static_metacall, 0, 0}
};


const QMetaObject *zLProjet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zLProjet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zLProjet.stringdata))
        return static_cast<void*>(const_cast< zLProjet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int zLProjet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
