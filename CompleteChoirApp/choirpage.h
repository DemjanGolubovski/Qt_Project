#ifndef CHOIRPAGE_H
#define CHOIRPAGE_H

#include <QWidget>
#include <QAudioDeviceInfo>


namespace Ui {
class ChoirPage;
}

class ChoirPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChoirPage(QWidget *parent = nullptr);
    ~ChoirPage();

    Ui::ChoirPage *getUi() const;
    void setUi(Ui::ChoirPage *value);

private:
    Ui::ChoirPage *ui;
};

#endif // CHOIRPAGE_H
