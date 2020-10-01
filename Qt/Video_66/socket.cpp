#include "socket.h"

Socket::Socket(QObject *parent) : QObject(parent)
{

}

void Socket::test(){
    socket=new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    qDebug()<<"Connecting...";
    socket->connectToHost("voidrealms.com", 80);
    if(!socket->waitForConnected(1000))
    {
        qDebug()<<"ERROR!";
        qDebug()<<socket->errorString();
    }
}
void Socket::connected()
{
    qDebug()<<"Connected";

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n");
}
void Socket::disconnected()
{
    qDebug()<<"Disconnected";
}
void Socket::bytesWritten(qint64 bytes)
{
    qDebug()<<"we wrote "<<bytes;
}
void Socket::readyRead()
{
    qDebug()<<"Reading...";
    qDebug()<<socket->readAll();
}
