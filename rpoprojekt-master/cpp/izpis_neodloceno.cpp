#include "izpis_neodloceno.h"
#include "ui_izpis_neodloceno.h"

izpis_neodloceno::izpis_neodloceno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izpis_neodloceno)
{
    ui->setupUi(this);
}

izpis_neodloceno::~izpis_neodloceno()
{
    delete ui;
}
