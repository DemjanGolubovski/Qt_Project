#include "sockettest.h"

socketTest::socketTest(QObject *parent) : QObject(parent)
{

}

void socketTest::connect(){
    // connected
    socket = new QTcpSocket(this);
    socket->connectToHost("google.com", 80);
    if(socket->waitForConnected(3000)){
        qDebug() <<"Connected";

        // sent data
        socket->write("Hello server\r\n\r\n\r\n");

        socket->waitForBytesWritten(1000);

        // got data
        socket->waitForReadyRead(3000);
        qDebug()<<"Reading:"<<socket->bytesAvailable();

        qDebug()<<socket->readAll();

        // close connection
        socket->close();
    }
    else{
        qDebug() <<"Not COnnected";
    }
}
