#ifndef TEXTTOSPEECH_H
#define TEXTTOSPEECH_H

#include <QObject>
#include <QAxObject>

class TextToSpeech : public QObject
{
    Q_OBJECT
public:
    explicit TextToSpeech(QObject *parent = 0);
    bool say(QString text);
    void setRate(int rate);
    void setVolume(int volume); //0~100
signals:

public slots:
    void _handleEvent(QString text,int arc,void* argc);
private:
    bool    _init();

    QAxObject           _voice;
    bool                _isInit;
    bool                _isSpeaking;


};

#endif // TEXTTOSPEECH_H
