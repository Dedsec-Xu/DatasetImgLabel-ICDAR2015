/****************************************************************************
** Meta object code from reading C++ file 'my_img_display_label.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../my_img_display_label.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_img_display_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_my_img_display_label_t {
    QByteArrayData data[11];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_img_display_label_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_img_display_label_t qt_meta_stringdata_my_img_display_label = {
    {
QT_MOC_LITERAL(0, 0, 20), // "my_img_display_label"
QT_MOC_LITERAL(1, 21, 20), // "ImgLabelMousePressed"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 18), // "ImgLabelMouseMoved"
QT_MOC_LITERAL(4, 62, 21), // "ImgLabelMouseReleased"
QT_MOC_LITERAL(5, 84, 11), // "DeletedRect"
QT_MOC_LITERAL(6, 96, 13), // "FinishRectadd"
QT_MOC_LITERAL(7, 110, 12), // "RectNotValid"
QT_MOC_LITERAL(8, 123, 16), // "FinishRectModify"
QT_MOC_LITERAL(9, 140, 18), // "RectModifyNotValid"
QT_MOC_LITERAL(10, 159, 18) // "slot_DrawRectStart"

    },
    "my_img_display_label\0ImgLabelMousePressed\0"
    "\0ImgLabelMouseMoved\0ImgLabelMouseReleased\0"
    "DeletedRect\0FinishRectadd\0RectNotValid\0"
    "FinishRectModify\0RectModifyNotValid\0"
    "slot_DrawRectStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my_img_display_label[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void my_img_display_label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        my_img_display_label *_t = static_cast<my_img_display_label *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ImgLabelMousePressed(); break;
        case 1: _t->ImgLabelMouseMoved(); break;
        case 2: _t->ImgLabelMouseReleased(); break;
        case 3: _t->DeletedRect(); break;
        case 4: _t->FinishRectadd(); break;
        case 5: _t->RectNotValid(); break;
        case 6: _t->FinishRectModify(); break;
        case 7: _t->RectModifyNotValid(); break;
        case 8: _t->slot_DrawRectStart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::ImgLabelMousePressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::ImgLabelMouseMoved)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::ImgLabelMouseReleased)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::DeletedRect)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::FinishRectadd)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::RectNotValid)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::FinishRectModify)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (my_img_display_label::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&my_img_display_label::RectModifyNotValid)) {
                *result = 7;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject my_img_display_label::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_my_img_display_label.data,
      qt_meta_data_my_img_display_label,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *my_img_display_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my_img_display_label::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_my_img_display_label.stringdata0))
        return static_cast<void*>(const_cast< my_img_display_label*>(this));
    return QLabel::qt_metacast(_clname);
}

int my_img_display_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void my_img_display_label::ImgLabelMousePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void my_img_display_label::ImgLabelMouseMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void my_img_display_label::ImgLabelMouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void my_img_display_label::DeletedRect()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void my_img_display_label::FinishRectadd()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void my_img_display_label::RectNotValid()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void my_img_display_label::FinishRectModify()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void my_img_display_label::RectModifyNotValid()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
