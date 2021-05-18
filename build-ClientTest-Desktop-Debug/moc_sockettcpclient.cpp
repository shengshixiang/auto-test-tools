/****************************************************************************
** Meta object code from reading C++ file 'sockettcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ClientTest/sockettcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sockettcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketTCPClient_t {
    QByteArrayData data[11];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketTCPClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketTCPClient_t qt_meta_stringdata_SocketTCPClient = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SocketTCPClient"
QT_MOC_LITERAL(1, 16, 29), // "on_m_connectServerBtn_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 71, 14), // "ClientRecvData"
QT_MOC_LITERAL(5, 86, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 110, 13), // "handleTimeout"
QT_MOC_LITERAL(7, 124, 17), // "envir_temper_read"
QT_MOC_LITERAL(8, 142, 5), // "sleep"
QT_MOC_LITERAL(9, 148, 4), // "msec"
QT_MOC_LITERAL(10, 153, 31) // "on_m_connectServerBtn_2_clicked"

    },
    "SocketTCPClient\0on_m_connectServerBtn_clicked\0"
    "\0on_pushButton_2_clicked\0ClientRecvData\0"
    "on_pushButton_3_clicked\0handleTimeout\0"
    "envir_temper_read\0sleep\0msec\0"
    "on_m_connectServerBtn_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketTCPClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void SocketTCPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketTCPClient *_t = static_cast<SocketTCPClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_m_connectServerBtn_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->ClientRecvData(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->handleTimeout(); break;
        case 5: _t->envir_temper_read(); break;
        case 6: _t->sleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_m_connectServerBtn_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SocketTCPClient::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SocketTCPClient.data,
      qt_meta_data_SocketTCPClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SocketTCPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketTCPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SocketTCPClient.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SocketTCPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
