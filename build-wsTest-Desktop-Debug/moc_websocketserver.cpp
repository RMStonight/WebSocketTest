/****************************************************************************
** Meta object code from reading C++ file 'websocketserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wsTest/websocketserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocketserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebSocketServer_t {
    QByteArrayData data[16];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebSocketServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebSocketServer_t qt_meta_stringdata_WebSocketServer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WebSocketServer"
QT_MOC_LITERAL(1, 16, 14), // "needUpdateList"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 36), // "QMap<QPair<QString,int>,QWebS..."
QT_MOC_LITERAL(4, 69, 7), // "clients"
QT_MOC_LITERAL(5, 77, 12), // "getClientMsg"
QT_MOC_LITERAL(6, 90, 9), // "msgHeader"
QT_MOC_LITERAL(7, 100, 7), // "message"
QT_MOC_LITERAL(8, 108, 10), // "promptInfo"
QT_MOC_LITERAL(9, 119, 3), // "msg"
QT_MOC_LITERAL(10, 123, 15), // "onNewConnection"
QT_MOC_LITERAL(11, 139, 18), // "socketDisconnected"
QT_MOC_LITERAL(12, 158, 18), // "processTextMessage"
QT_MOC_LITERAL(13, 177, 22), // "sendMessageToIPAndPort"
QT_MOC_LITERAL(14, 200, 9), // "ipAddress"
QT_MOC_LITERAL(15, 210, 4) // "port"

    },
    "WebSocketServer\0needUpdateList\0\0"
    "QMap<QPair<QString,int>,QWebSocket*>\0"
    "clients\0getClientMsg\0msgHeader\0message\0"
    "promptInfo\0msg\0onNewConnection\0"
    "socketDisconnected\0processTextMessage\0"
    "sendMessageToIPAndPort\0ipAddress\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebSocketServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,
       8,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   60,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,
      12,    1,   62,    2, 0x0a /* Public */,
      13,    3,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   14,   15,    9,

       0        // eod
};

void WebSocketServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebSocketServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->needUpdateList((*reinterpret_cast< const QMap<QPair<QString,int>,QWebSocket*>(*)>(_a[1]))); break;
        case 1: _t->getClientMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->promptInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onNewConnection(); break;
        case 4: _t->socketDisconnected(); break;
        case 5: _t->processTextMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->sendMessageToIPAndPort((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebSocketServer::*)(const QMap<QPair<QString,int>,QWebSocket*> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServer::needUpdateList)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WebSocketServer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServer::getClientMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WebSocketServer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketServer::promptInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WebSocketServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WebSocketServer.data,
    qt_meta_data_WebSocketServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebSocketServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebSocketServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebSocketServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebSocketServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void WebSocketServer::needUpdateList(const QMap<QPair<QString,int>,QWebSocket*> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebSocketServer::getClientMsg(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebSocketServer::promptInfo(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
