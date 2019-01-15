/****************************************************************************
** Meta object code from reading C++ file 'img_zooming.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../img_zooming.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'img_zooming.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgZoom_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgZoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgZoom_t qt_meta_stringdata_ImgZoom = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ImgZoom"
QT_MOC_LITERAL(1, 8, 11), // "onUpClicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "onDownClicked"
QT_MOC_LITERAL(4, 35, 13), // "OnLiftClicked"
QT_MOC_LITERAL(5, 49, 14), // "OnRightClicked"
QT_MOC_LITERAL(6, 64, 15), // "onLittleClicked"
QT_MOC_LITERAL(7, 80, 12), // "onBigClicked"
QT_MOC_LITERAL(8, 93, 10), // "paintEvent"
QT_MOC_LITERAL(9, 104, 12), // "QPaintEvent*"
QT_MOC_LITERAL(10, 117, 5) // "event"

    },
    "ImgZoom\0onUpClicked\0\0onDownClicked\0"
    "OnLiftClicked\0OnRightClicked\0"
    "onLittleClicked\0onBigClicked\0paintEvent\0"
    "QPaintEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgZoom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void ImgZoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImgZoom *_t = static_cast<ImgZoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUpClicked(); break;
        case 1: _t->onDownClicked(); break;
        case 2: _t->OnLiftClicked(); break;
        case 3: _t->OnRightClicked(); break;
        case 4: _t->onLittleClicked(); break;
        case 5: _t->onBigClicked(); break;
        case 6: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ImgZoom::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImgZoom.data,
      qt_meta_data_ImgZoom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImgZoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgZoom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImgZoom.stringdata0))
        return static_cast<void*>(const_cast< ImgZoom*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImgZoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
