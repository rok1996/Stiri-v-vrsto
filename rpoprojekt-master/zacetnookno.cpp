#include "zacetnookno.h"
#include "ui_zacetnookno.h"

ZacetnoOkno::ZacetnoOkno(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ZacetnoOkno)
{
  ui->setupUi(this);
}

ZacetnoOkno::~ZacetnoOkno()
{
  delete ui;
}
