/****************************************************************************
** Meta object code from reading C++ file 'dumbcalc.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../dumbcalc/dumbcalc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dumbcalc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dumbcalc_t {
    const uint offsetsAndSize[32];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_dumbcalc_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_dumbcalc_t qt_meta_stringdata_dumbcalc = {
    {
QT_MOC_LITERAL(0, 8), // "dumbcalc"
QT_MOC_LITERAL(9, 12), // "digitClicked"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 20), // "unaryOperatorClicked"
QT_MOC_LITERAL(44, 23), // "additiveOperatorClicked"
QT_MOC_LITERAL(68, 29), // "multiplicativeOperatorClicked"
QT_MOC_LITERAL(98, 12), // "equalClicked"
QT_MOC_LITERAL(111, 12), // "pointClicked"
QT_MOC_LITERAL(124, 17), // "changeSignClicked"
QT_MOC_LITERAL(142, 16), // "backspaceClicked"
QT_MOC_LITERAL(159, 5), // "clear"
QT_MOC_LITERAL(165, 8), // "clearAll"
QT_MOC_LITERAL(174, 11), // "clearMemory"
QT_MOC_LITERAL(186, 10), // "readMemory"
QT_MOC_LITERAL(197, 9), // "setMemory"
QT_MOC_LITERAL(207, 11) // "addToMemory"

    },
    "dumbcalc\0digitClicked\0\0unaryOperatorClicked\0"
    "additiveOperatorClicked\0"
    "multiplicativeOperatorClicked\0"
    "equalClicked\0pointClicked\0changeSignClicked\0"
    "backspaceClicked\0clear\0clearAll\0"
    "clearMemory\0readMemory\0setMemory\0"
    "addToMemory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dumbcalc[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    0,  110,    2, 0x08,   13 /* Private */,
      15,    0,  111,    2, 0x08,   14 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dumbcalc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dumbcalc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->digitClicked(); break;
        case 1: _t->unaryOperatorClicked(); break;
        case 2: _t->additiveOperatorClicked(); break;
        case 3: _t->multiplicativeOperatorClicked(); break;
        case 4: _t->equalClicked(); break;
        case 5: _t->pointClicked(); break;
        case 6: _t->changeSignClicked(); break;
        case 7: _t->backspaceClicked(); break;
        case 8: _t->clear(); break;
        case 9: _t->clearAll(); break;
        case 10: _t->clearMemory(); break;
        case 11: _t->readMemory(); break;
        case 12: _t->setMemory(); break;
        case 13: _t->addToMemory(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject dumbcalc::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_dumbcalc.offsetsAndSize,
    qt_meta_data_dumbcalc,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_dumbcalc_t
, QtPrivate::TypeAndForceComplete<dumbcalc, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *dumbcalc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dumbcalc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dumbcalc.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dumbcalc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
