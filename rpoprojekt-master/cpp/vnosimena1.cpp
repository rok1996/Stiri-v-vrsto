#include "vnosimena1.h"
#include "ui_vnosimena1.h"

vnosImena1::vnosImena1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vnosImena1)
{
    ui->setupUi(this);
}

vnosImena1::~vnosImena1()
{
    delete ui;
}
