#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QDir myDir("C:/Qt");
//    if(myDir.exists())
//        qDebug() << "It does exist";
//    else
//        qDebug() << "It does not exist";

//    QDir myDir;
//    foreach(QFileInfo obj, myDir.drives()){
//        qDebug() << obj.path();
//    }

//    QDir myDir;
//    myDir.mkdir("NewQtFolder");
//    myDir.mkpath("C:/Users/gdemj/Desktop/Qt Projects/Qt_Project/Qt/build-Video_11-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/NewNewFolder/AndAgain");

    QDir myDir("C:/Users/gdemj/Desktop");
    foreach(QFileInfo obj, myDir.entryInfoList()){
        if(obj.isDir())
            qDebug()<< "Dir: "<<obj.absoluteFilePath();
        if(obj.isFile())
            qDebug()<< "File: "<<obj.absoluteFilePath();
    }


    return a.exec();
}
