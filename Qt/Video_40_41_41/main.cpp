#include <QCoreApplication>
#include <QMap>
#include <QHash>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Video 40
//    QMap<int, QString> mapa;
//    mapa.insert(1, "Demi");
//    mapa.insert(2, "Demki");
//    mapa.insert(3, "Demce");

//    foreach(int i, mapa.keys()){
//        qDebug()<<mapa.value(i)<<" = "<<mapa[i];
//    }

//    QMapIterator<int, QString> iter(mapa);
//    while(iter.hasNext()){
//        iter.next();
//        qDebug()<<iter.key()<<" "<<iter.value();
//    }

//    Video 41 Isto kako QMap samo zameni sekade QMap so QHash(QHash samo hasira keys i za prebaruvanje e mn pobrzo od QMap)

//    Video 42
    QStringList str_lst;
//    str_lst.append("HEllo");
//    str_lst.append("World");

//    foreach(QString str, str_lst){
//        qDebug()<<str;
//    }
    QString str= "a,b,c,d,e,f";
    str_lst=str.split(",");

    str_lst.replaceInStrings("a", "aquaman");

    QString str_again=str_lst.join(",");
    qDebug()<<"Nov string = "<<str_again;

    foreach(QString str, str_lst){
        qDebug()<<str;
     }

    return a.exec();
}
