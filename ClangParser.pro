QT       += core gui
QT += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# INCLUDEPATH += C:/CustomInstall/libclang/include
# LIBS += -LC:/CustomInstall/libclang/lib -lclang


INCLUDEPATH += "C:/Program Files/LLVM/include"
LIBS += -L"C:/Program Files/LLVM/lib" -lclang

# QMAKE_CXXFLAGS += -v
# QMAKE_LFLAGS += -v


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clangparser.cpp \
    classinfoprovider.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    clangparser.h \
    classinfoprovider.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
