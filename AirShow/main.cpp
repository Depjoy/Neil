#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AudioOutput.h"
#include "TextToSpeech.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    TextToSpeech *_textToSpeech = new TextToSpeech();
    _textToSpeech->setRate(-10);
    _textToSpeech->setVolume(30);
    _textToSpeech->say("Hello World");
    return app.exec();
}

