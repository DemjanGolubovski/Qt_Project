#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w=new QWidget(); // ova se koristi deka layout ne e widget i nema opcija show

//    QLabel *lbl=new QLabel("<b>Hello</b> <i>World</i>");
//    lbl->show();

//    QPushButton *btn_1=new QPushButton("OK");
//    QPushButton *btn_2=new QPushButton("OK!");
//    QPushButton *btn_3=new QPushButton("OK!!");

//    QHBoxLayout *layout=new QHBoxLayout(); // isto i se vertical layer
//    layout->addWidget(lbl);
//    layout->addWidget(btn_1);
//    layout->addWidget(btn_2);
//    layout->addWidget(btn_3);

    QLabel *lbl=new QLabel("Name:");
    QLineEdit *line=new QLineEdit();
    QPushButton *btn=new QPushButton("Gooooo!!!");

    QGridLayout *layout=new QGridLayout();

    layout->addWidget(lbl, 0, 0);
    layout->addWidget(line, 0, 1);
    layout->addWidget(btn, 1, 1, 2, 2); // kje zafakje 2 red i 2 koloni



    w->setLayout(layout);
    w->show();

    return a.exec();
}
