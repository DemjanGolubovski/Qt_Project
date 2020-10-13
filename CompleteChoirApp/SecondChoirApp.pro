QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChoirLeaderModel.cpp \
    User.cpp \
    choirdelegate.cpp \
    choirpage.cpp \
    customlabel.cpp \
    delegate.cpp \
    filldatapage.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ChoirLeaderModel.h \
    User.h \
    choirdelegate.h \
    choirpage.h \
    customlabel.h \
    delegate.h \
    filldatapage.h \
    loginpage.h \
    mainwindow.h

FORMS += \
    choirpage.ui \
    filldatapage.ui \
    loginpage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
