#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <QString>
#include <QObject>
#include <QMediaPlayer>

class Microphone : public QObject
{
    Q_OBJECT
public:
    explicit Microphone(QObject *parent = nullptr);

    QString getAudio_url() const;
    void setAudio_url(const QString &value);

    QMediaPlayer *getAudio_player() const;
    void setAudio_player(QMediaPlayer *value);

private slots:
    // TODO: the needed slots are in the AudioPlayer project

private:
    QString audio_url;
    QMediaPlayer *audio_player;
};

#endif // MICROPHONE_H
