#include <QDebug>
#include "AudioWorker.h"

AudioWorker::AudioWorker(QObject *parent)
    : QObject(parent)
#ifdef AUDIO_ENABLED
    , _pVoice(NULL)
#endif
    , _inited(false)
{

}

AudioWorker::~AudioWorker()
{
#ifdef AUDIO_ENABLED
    if(_pVoice){
        _pVoice->Release();
        _pVoice = NULL;
    }
    ::CoUninitialize();
#endif
}

bool AudioWorker::_init()
{
#ifdef AUDIO_ENABLED
    if(FAILED(::CoInitialize(NULL))){
        qDebug() << "ERROR: initialize COM failed! ";
        return false;
    }else{
        HRESULT hr = CoCreateInstance(CLSID_SpVoice,NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&_pVoice);
        if(FAILED(hr)){
            qDebug() << "ERROR: Initializing voice for audio output failed!";
            return false;
        }
    }
    return true;
#else
    qWarning() << "WARNING: Audio is disable !";
    return false;
#endif
}

void AudioWorker::speakOut(int severity,const QString& text)
{
    if(!_inited){
        if(!_init())
            return;
        _inited = true;
    }
    _fuseTextWithSeverity(severity, text);
}

void AudioWorker::_fuseTextWithSeverity(int severity,const QString& text)
{
    QString final = text;
    switch (severity) {
    case TEXT_SEVERITY_NORMAL:
        break;
    case TEXT_SEVERITY_WARNING:
        final.insert(0,"Warning");
    case TEXT_SEVERITY_ERROR:
        final.insert(0,"Error");
        break;
    case TEXT_SEVERITY_CRITAL:
        final.insert(0,"Crital");
        break;
    default:
        break;
    }
#ifdef AUDIO_ENABLED
    _pVoice->Speak(final.toStdWString().c_str(),SPF_DEFAULT,NULL);
#endif
}
