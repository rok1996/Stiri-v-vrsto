#include "vnosimena2.h"
#include "ui_vnosimena2.h"

vnosImena2::vnosImena2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vnosImena2)
{
    ui->setupUi(this);
}

vnosImena2::~vnosImena2()
{
    delete ui;
}
