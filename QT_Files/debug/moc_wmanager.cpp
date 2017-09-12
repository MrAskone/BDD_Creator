/****************************************************************************
** Meta object code from reading C++ file 'wmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cpp/wmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WManager_t {
    QByteArrayData data[15];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WManager_t qt_meta_stringdata_WManager = {
    {
QT_MOC_LITERAL(0, 0, 8), // "WManager"
QT_MOC_LITERAL(1, 9, 17), // "propStringChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "largeurBoutonChanged"
QT_MOC_LITERAL(4, 49, 13), // "setPropString"
QT_MOC_LITERAL(5, 63, 1), // "a"
QT_MOC_LITERAL(6, 65, 12), // "propString_r"
QT_MOC_LITERAL(7, 78, 16), // "setLargeurBouton"
QT_MOC_LITERAL(8, 95, 1), // "i"
QT_MOC_LITERAL(9, 97, 13), // "largeurBouton"
QT_MOC_LITERAL(10, 111, 15), // "sendActionToCpp"
QT_MOC_LITERAL(11, 127, 9), // "parametre"
QT_MOC_LITERAL(12, 137, 13), // "testActionQML"
QT_MOC_LITERAL(13, 151, 3), // "nom"
QT_MOC_LITERAL(14, 155, 10) // "propString"

    },
    "WManager\0propStringChanged\0\0"
    "largeurBoutonChanged\0setPropString\0a\0"
    "propString_r\0setLargeurBouton\0i\0"
    "largeurBouton\0sendActionToCpp\0parametre\0"
    "testActionQML\0nom\0propString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   61,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    2,   69,    2, 0x02 /* Public */,
      10,    1,   74,    2, 0x22 /* Public | MethodCloned */,
      12,    1,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Int,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   13,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00495103,
       9, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void WManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WManager *_t = static_cast<WManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->propStringChanged(); break;
        case 1: _t->largeurBoutonChanged(); break;
        case 2: _t->setPropString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { QString _r = _t->propString_r();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setLargeurBouton((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: { int _r = _t->largeurBouton();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->sendActionToCpp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->sendActionToCpp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->testActionQML((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WManager::propStringChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WManager::largeurBoutonChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WManager *_t = static_cast<WManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->propString_r(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->largeurBouton(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WManager *_t = static_cast<WManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPropString(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLargeurBouton(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject WManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WManager.data,
      qt_meta_data_WManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WManager.stringdata0))
        return static_cast<void*>(const_cast< WManager*>(this));
    return QObject::qt_metacast(_clname);
}

int WManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WManager::propStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WManager::largeurBoutonChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
