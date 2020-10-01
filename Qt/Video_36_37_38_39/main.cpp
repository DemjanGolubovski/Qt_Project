#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    Video 36
//    QList<int> list;
//    for(int i=0; i<10; i++){
//        list.append(i);
//    }

//    list.removeOne(9);

//    foreach(int num, list){
//        qDebug()<<num;
//    }

//    Video 37
//    QList<int> list;
//    for(int i=0; i<10; i++){
//        list.append(i);
//    }
//    QListIterator<int> iter(list);
//    while(iter.hasNext()){
//        qDebug() << iter.next();
//    }
//    iter.toBack();
//    while(iter.hasPrevious())
//    {
//        qDebug()<<iter.previous();
//        if(iter.hasPrevious())
//            qDebug()<<"Next..."<<iter.peekPrevious();
//    }

//    Video 38
//    QList<int> list;
//    for(int i=0; i<10; i++){
//        list.append(i);
//    }
//    QMutableListIterator<int> iter(list);
//    while(iter.hasNext()){
//        if(iter.next()%2==0)
//            iter.remove();
//    }
//    iter.toFront();
//    while(iter.hasNext()){
//        qDebug()<<iter.next();
//    }

//    Video 39
//    isto kako QLinkedList so istite metodi
//    QLinkedList<int> l_list;
    return a.exec();
}
