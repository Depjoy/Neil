TEMPLATE = app

# axcontainer used to TextToSpeech
QT += qml quick location axcontainer
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
    src/Audio/TextToSpeech.h

SOURCES += main.cpp \
    src/Audio/AudioOutput.cpp \
    src/Audio/AudioWorker.cpp \
    src/Audio/TextToSpeech.cpp

contains(DEFINES, DISABLE_AUDIO){
    message("Disable audio")
}else:win32{
    message("Include windows TTS Libary")
    LIBS += -lOle32
    DEFINES += AUDIO_ENABLED
}


# GeoLocation
INCLUDEPATH += src/GeoLocation \

HEADERS += \
    src/GeoLocation/GeoServiceProviderFactory.h \

SOURCES += \
    src/GeoLocation/GeoServiceProviderFactory.cpp \

DISTFILES += \
    src/GeoLocation/map_plugin.json

