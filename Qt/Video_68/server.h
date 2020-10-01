#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include "thread.h"

class Server : public QTcpServer
{
    // Koga e ova postaveno dava error "undefined reference to 'vtable for Server'"
//    Q_OBJECT
public:
    explicit Server(QObject *parent=0);
    void startServer();
signals:

public slots:

protected:
    void incomingConnection(int handle);
};

#endif // SERVER_H
