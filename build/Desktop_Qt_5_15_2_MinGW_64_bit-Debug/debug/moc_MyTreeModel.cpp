/****************************************************************************
** Meta object code from reading C++ file 'MyTreeModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MyTreeModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTreeModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreeModels__MyTreeModel_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreeModels__MyTreeModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreeModels__MyTreeModel_t qt_meta_stringdata_TreeModels__MyTreeModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "TreeModels::MyTreeModel"
QT_MOC_LITERAL(1, 24, 11), // "QML.Element"
QT_MOC_LITERAL(2, 36, 4), // "auto"
QT_MOC_LITERAL(3, 41, 7), // "getRole"
QT_MOC_LITERAL(4, 49, 0), // ""
QT_MOC_LITERAL(5, 50, 8), // "tablePos"
QT_MOC_LITERAL(6, 59, 12), // "getTableName"
QT_MOC_LITERAL(7, 72, 10) // "getColumns"

    },
    "TreeModels::MyTreeModel\0QML.Element\0"
    "auto\0getRole\0\0tablePos\0getTableName\0"
    "getColumns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeModels__MyTreeModel[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // methods: name, argc, parameters, tag, flags
       3,    1,   31,    4, 0x02 /* Public */,
       6,    1,   34,    4, 0x02 /* Public */,
       7,    0,   37,    4, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QByteArray, QMetaType::Int,    5,
    QMetaType::QByteArray, QMetaType::Int,    5,
    QMetaType::Int,

       0        // eod
};

void TreeModels::MyTreeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTreeModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QByteArray _r = _t->getRole((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 1: { QByteArray _r = _t->getTableName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getColumns();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TreeModels::MyTreeModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QStandardItemModel::staticMetaObject>(),
    qt_meta_stringdata_TreeModels__MyTreeModel.data,
    qt_meta_data_TreeModels__MyTreeModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TreeModels::MyTreeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeModels::MyTreeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreeModels__MyTreeModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int TreeModels::MyTreeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
