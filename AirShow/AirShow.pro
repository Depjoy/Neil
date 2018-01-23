TEMPLATE = app

QT += qml quick
CONFIG += c++11



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

# Audio output
INCLUDEPATH += src/Audio \

HEADERS += \
    src/Audio/AudioOutput.h \
    src/Audio/AudioWorker.h \

SOURCES += main.cpp \
    src/Audio/AudioOutput.cpp \
    src/Audio/AudioWorker.cpp \

#contains(DEFINES, DISABLE_AUDIO){
#    message("Disable audio")
#}else:
#WindowsBuild{
win32{
    message("Include windows TTS Libary")
    LIBS += -lOle32
    DEFINES += AUDIO_ENABLED
}
#    message("step out")
#    LIBS += -lOle32
