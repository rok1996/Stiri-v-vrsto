#include "izpis_zmagovalca.h"
#include "ui_izpis_zmagovalca.h"


Izpis_zmagovalca::Izpis_zmagovalca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Izpis_zmagovalca)
{
    ui->setupUi(this);
}

Izpis_zmagovalca::~Izpis_zmagovalca()
{
    delete ui;
}
