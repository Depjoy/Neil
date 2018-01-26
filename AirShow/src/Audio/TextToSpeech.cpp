#include "TextToSpeech.h"
#include "QDebug"
TextToSpeech::TextToSpeech(QObject *parent)
    : QObject(parent)
    , _isInit(false)
    , _isSpeaking(false)
{
    _isInit = _init();
    if(_isInit){
        connect(&_voice,    SIGNAL(signal(QString,int, void*)), this,   SLOT(_handleEvent(QString,int,void*)));
    }
}

bool TextToSpeech::_init(void)
{
    return _voice.setControl("96749377-3391-11D2-9EE3-00C04F797396");
}

void TextToSpeech::_handleEvent(QString text, int arc, void *argc)
{
    if(text == "EndStream(int,QVariant)"){
        _isSpeaking = false;
    }
}

bool TextToSpeech::say(QString text)
{
    if(!_isInit)
        return false;

    int res = _voice.dynamicCall("Speak(QString, SpeechVoiceSpeakFlags)", text ,1).toInt();
    _isSpeaking = true;

    return res;
}

void TextToSpeech::setRate(int rate)  //-10~10
{
    if(!_isInit)
        return;
    _voice.dynamicCall("SetRate(int)",rate);
}

void TextToSpeech::setVolume(int volume)
{
    if(!_isInit)
        return;
    _voice.dynamicCall("SetVolume(int)",volume);
}
