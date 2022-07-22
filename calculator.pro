QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c c++17

MAKEFILE = RealMakefile

OBJECTS_DIR= objs
MOC_DIR= objs
#RCC_DIR = objs
UI_DIR = ui
DESTDIR= .


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	frontend/actions.cpp \
	frontend/calculator.cpp \
    frontend/main.cpp \
	frontend/qcustomplot.cpp \
	backend/calc.c \
	backend/converting.c \
	backend/smartcalc.c \
	backend/validate.c \
    frontend/credit_debit.cpp \

HEADERS += \
	frontend/qcustomplot.h \
	frontend/calculator.h \
	backend/smartcalc.h \
    frontend/credit_debit.h


FORMS += ui/calculator.ui \
	ui/credit_debit.ui

QMAKE_EXTRA_TARGETS += test gcov_report
test.commands = make -C .. test
gcov_report.commands = make -C .. gcov_report
clean.commands += make -C .. clean


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
