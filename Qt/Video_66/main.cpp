#include <QCoreApplication>
#include "socket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Socket mSocket;
    mSocket.test();
    return a.exec();
}
