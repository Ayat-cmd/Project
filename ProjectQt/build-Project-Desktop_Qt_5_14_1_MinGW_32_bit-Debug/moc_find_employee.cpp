/****************************************************************************
** Meta object code from reading C++ file 'find_employee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Project/find_employee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'find_employee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Find_employee_t {
    QByteArrayData data[16];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Find_employee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Find_employee_t qt_meta_stringdata_Find_employee = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Find_employee"
QT_MOC_LITERAL(1, 14, 23), // "DataWorkers_slot_Signal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 8), // "QString&"
QT_MOC_LITERAL(4, 48, 3), // "res"
QT_MOC_LITERAL(5, 52, 21), // "on_OkFind_Btn_clicked"
QT_MOC_LITERAL(6, 74, 24), // "on_OkFindSNP_Btn_clicked"
QT_MOC_LITERAL(7, 99, 26), // "on_OkFindPhone_Btn_clicked"
QT_MOC_LITERAL(8, 126, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 148, 26), // "on_backFindSNP_Btn_clicked"
QT_MOC_LITERAL(10, 175, 31), // "on_surnameFind_line_textChanged"
QT_MOC_LITERAL(11, 207, 4), // "arg1"
QT_MOC_LITERAL(12, 212, 28), // "on_nameFind_line_textChanged"
QT_MOC_LITERAL(13, 241, 34), // "on_patranomicFind_line_textCh..."
QT_MOC_LITERAL(14, 276, 29), // "on_phoneFind_line_textChanged"
QT_MOC_LITERAL(15, 306, 29) // "on_Back_find_to_phine_clicked"

    },
    "Find_employee\0DataWorkers_slot_Signal\0"
    "\0QString&\0res\0on_OkFind_Btn_clicked\0"
    "on_OkFindSNP_Btn_clicked\0"
    "on_OkFindPhone_Btn_clicked\0"
    "on_pushButton_clicked\0on_backFindSNP_Btn_clicked\0"
    "on_surnameFind_line_textChanged\0arg1\0"
    "on_nameFind_line_textChanged\0"
    "on_patranomicFind_line_textChanged\0"
    "on_phoneFind_line_textChanged\0"
    "on_Back_find_to_phine_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Find_employee[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void Find_employee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Find_employee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataWorkers_slot_Signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_OkFind_Btn_clicked(); break;
        case 2: _t->on_OkFindSNP_Btn_clicked(); break;
        case 3: _t->on_OkFindPhone_Btn_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_backFindSNP_Btn_clicked(); break;
        case 6: _t->on_surnameFind_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_nameFind_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_patranomicFind_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_phoneFind_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_Back_find_to_phine_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Find_employee::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Find_employee::DataWorkers_slot_Signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Find_employee::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Find_employee.data,
    qt_meta_data_Find_employee,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Find_employee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Find_employee::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Find_employee.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Find_employee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Find_employee::DataWorkers_slot_Signal(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
