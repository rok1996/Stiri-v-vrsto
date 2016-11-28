#ifndef IZPIS_NEODLOCENO_H
#define IZPIS_NEODLOCENO_H

#include <QDialog>

namespace Ui {
class izpis_neodloceno;
}

class izpis_neodloceno : public QDialog
{
    Q_OBJECT

public:
    explicit izpis_neodloceno(QWidget *parent = 0);
    ~izpis_neodloceno();

private slots:

private:
    Ui::izpis_neodloceno *ui;
};

#endif // IZPIS_NEODLOCENO_H
