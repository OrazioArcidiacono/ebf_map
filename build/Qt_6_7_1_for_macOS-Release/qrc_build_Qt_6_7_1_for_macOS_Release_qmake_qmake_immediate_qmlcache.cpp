/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /Users/orazioarcidiacono/EBF_Map/EBFMap.qml
  0x0,0x0,0x0,0x3c,
  0x69,
  0x6d,0x70,0x6f,0x72,0x74,0x20,0x51,0x74,0x51,0x75,0x69,0x63,0x6b,0x20,0x32,0x2e,
  0x31,0x35,0xa,0x69,0x6d,0x70,0x6f,0x72,0x74,0x20,0x51,0x74,0x51,0x75,0x69,0x63,
  0x6b,0x2e,0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x73,0x20,0x32,0x2e,0x31,0x35,0xa,
  0xa,0x49,0x74,0x65,0x6d,0x20,0x7b,0xa,0xa,0x7d,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // EBFMap.qml
  0x0,0xa,
  0x3,0x8a,0x7d,0x5c,
  0x0,0x45,
  0x0,0x42,0x0,0x46,0x0,0x4d,0x0,0x61,0x0,0x70,0x0,0x2e,0x0,0x71,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/EBFMap.qml
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x8f,0xf6,0x71,0x3d,0xb9,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_build_Qt_6_7_1_for_macOS_Release_qmake_qmake_immediate_qmlcache)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
