#include "thread.h"

Thread::Thread(int ID, QObject *parent): QThread(parent)
{
    this->socketDescriptor=ID;
}

void Thread::run(){
    qDebug()<<"Starting thread...";
    socket=new QTcpSocket();
//    if(!socket->setSocketDescriptor(socketDescriptor))
//    {
//        emit error(socket->error());
//    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    qDebug()<<"Socket connected..."<<socketDescriptor;

    exec(); // mora da se koristi za da ne se unisti threadod koga kje dojde do }
}

void Thread::readyRead(){
    QByteArray data=socket->readAll();

    qDebug()<<"Data: "<<data;

    socket->write(data);
}
void Thread::disconnected(){
    qDebug()<<"Disconnected..."<<socketDescriptor;
    socket->deleteLater();
    exit(0); // so ova go unistuvame thread-od
}
