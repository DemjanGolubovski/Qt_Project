#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QThread
{
//    Q_OBJECT
public:
    explicit Thread(int ID, QObject *parent=0);
    void run() override;
signals:
//    void error(QTcpSocket::SocketError s_err);
public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // THREAD_H
