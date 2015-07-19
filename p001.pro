TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    F_Function.h \
    A_Settings.h \
    A_Header.h \
    C_KeyBoard.h \
    A_Paths.h

LIBS += -L/home/romanshevelev/irr/lib/Linux/ -lIrrlicht -lGL -lGLU -lXxf86vm -lXext -lX11
INCLUDEPATH += /home/romanshevelev/irr/include

OTHER_FILES += \
    res/mdl/ball.3ds \
    res/mdl/map.3ds \
    res/mdl/cube.x

copydata.commands = $(COPY_DIR) $$PWD/res $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
