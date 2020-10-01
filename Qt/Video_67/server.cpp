#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server=new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 8888)) // ako ne moze klient da se povrze treba da se smeni portata
        qDebug()<<"Not started";
    else
        qDebug()<<"Server started";
}

void Server::newConnection(){
    QTcpSocket *socket=server->nextPendingConnection();

    socket->write("Hello Client...\r\n\r\n\r\n");
    socket->flush();

    socket->waitForBytesWritten(2000);

    socket->close();
}
