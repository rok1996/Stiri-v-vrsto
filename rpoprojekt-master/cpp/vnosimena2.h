#ifndef VNOSIMENA2_H
#define VNOSIMENA2_H

#include <QDialog>

namespace Ui {
class vnosImena2;
}

class vnosImena2 : public QDialog
{
    Q_OBJECT

public:
    explicit vnosImena2(QWidget *parent = 0);
    ~vnosImena2();

private:
    Ui::vnosImena2 *ui;
};

#endif // VNOSIMENA2_H
