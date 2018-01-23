#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QObject>
#include <QThread>
#include "AudioWorker.h"

class AudioOutput : public QObject
{
    Q_OBJECT
public:
    explicit AudioOutput(QObject *parent = 0);
    ~AudioOutput();
    bool speakOut(int severity, const QString& text);
signals:
    void textToSpeak(int severity, const QString& text);

public slots:
private:
    QThread *               _thread;
    AudioWorker*            _audioWorker;
};

#endif // AUDIOOUTPUT_H
