#include "microphone.h"

Microphone::Microphone(QObject *parent):QObject(parent)
{
}

QString Microphone::getAudio_url() const
{
    return audio_url;
}

void Microphone::setAudio_url(const QString &value)
{
    audio_url = value;
}

QMediaPlayer *Microphone::getAudio_player() const
{
    return audio_player;
}

void Microphone::setAudio_player(QMediaPlayer *value)
{
    audio_player = value;
}
