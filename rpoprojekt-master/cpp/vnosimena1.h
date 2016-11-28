#ifndef VNOSIMENA1_H
#define VNOSIMENA1_H

#include <QDialog>

namespace Ui {
class vnosImena1;
}

class vnosImena1 : public QDialog
{
    Q_OBJECT

public:
    explicit vnosImena1(QWidget *parent = 0);
    ~vnosImena1();

private:
    Ui::vnosImena1 *ui;
};

#endif // VNOSIMENA1_H
