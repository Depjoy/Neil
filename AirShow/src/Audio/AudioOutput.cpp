#include <QDebug>
#include "AudioOutput.h"

AudioOutput::AudioOutput(QObject *parent)
    : QObject(parent)
    , _thread(new QThread())
    , _audioWorker(new AudioWorker())
{
   _audioWorker->moveToThread(_thread);
   connect(this,    &AudioOutput::textToSpeak,  _audioWorker,   &AudioWorker::speakOut);
   connect(_thread, &QThread::finished,         _thread,        &QObject::deleteLater);
   connect(_thread, &QThread::finished,         _audioWorker,   &QObject::deleteLater);
    _thread->start();
}

AudioOutput::~AudioOutput()
{
    _thread->quit();
}

bool AudioOutput::speakOut(int severity, const QString& text)
{
    emit textToSpeak(severity,text);
    return true;
}
