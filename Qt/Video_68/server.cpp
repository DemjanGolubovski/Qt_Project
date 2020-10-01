#include "server.h"

Server::Server(QObject *parent):QTcpServer(parent)
{
}

void Server::incomingConnection(int handle){
    qDebug()<<"Conecting..."<<handle;
    Thread *t=new Thread(handle, this);

    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));

    t->start();
}
void Server::startServer(){
    if(!this->listen(QHostAddress::Any, 5555))
    {
        qDebug()<<"Did not start";
    }
    else{
        qDebug()<<"Listening...";
    }
}
