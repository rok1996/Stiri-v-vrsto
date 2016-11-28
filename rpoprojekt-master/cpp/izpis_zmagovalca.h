#ifndef IZPIS_ZMAGOVALCA_H
#define IZPIS_ZMAGOVALCA_H

#include <QDialog>

namespace Ui {
class Izpis_zmagovalca;
}

class Izpis_zmagovalca : public QDialog
{
    Q_OBJECT

public:
    explicit Izpis_zmagovalca(QWidget *parent = 0);
    ~Izpis_zmagovalca();

private slots:

private:
    Ui::Izpis_zmagovalca *ui;
};

#endif // IZPIS_ZMAGOVALCA_H
