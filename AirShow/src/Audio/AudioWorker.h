#ifndef AUDIOWORKER_H
#define AUDIOWORKER_H

#include <QObject>
#ifdef AUDIO_ENABLED
#include <sapi.h>
#endif
class AudioWorker : public QObject
{
    Q_OBJECT
public:
    typedef enum __TEXT_SEVERITY{
        TEXT_SEVERITY_NORMAL = 0,
        TEXT_SEVERITY_WARNING,
        TEXT_SEVERITY_ERROR,
        TEXT_SEVERITY_CRITAL,
    }TEXT_SEVERITY;

    explicit AudioWorker(QObject *parent = 0);
    ~AudioWorker();
signals:

public slots:
    void speakOut(int severity, const QString& text);
private:
    bool _init(void);
    void _fuseTextWithSeverity(int severity, const QString& text);

    bool            _inited;
#ifdef AUDIO_ENABLED
    ISpVoice*       _pVoice;
#endif
};

#endif // AUDIOWORKER_H
