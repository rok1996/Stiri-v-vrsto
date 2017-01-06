#include "zacetnookno.h"
#include "ui_zacetnookno.h"
#include <QMessageBox>

ZacetnoOkno::ZacetnoOkno(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ZacetnoOkno)
{
  ui->setupUi(this);
  /*connect(ui->btnZacni, SIGNAL(clicked()), this, SLOT(onKlik()));
  connect(ui->btnNaGlavo, SIGNAL(clicked()), this, SLOT(onKlik()));*/
}

/*void ZacetnoOkno::onKlik()
{
    QPushButton* klikBtn = qobject_cast<QPushButton*>(sender());
    if (klikBtn)
    {
        const QString klikBtnText = klikBtn->text();
        const QString klikBtnName = klikBtn->objectName();
    }
}*/

ZacetnoOkno::~ZacetnoOkno()
{
  delete ui;
}

void ZacetnoOkno::on_btnZacni_clicked()
{
    tip=1;
    this->close();
}

void ZacetnoOkno::on_btnNaGlavo_clicked()
{
    tip=3;
    this->close();
}

void ZacetnoOkno::on_pushButton_clicked()
{
    tip=2;
    this->close();
}

void ZacetnoOkno::on_btnZapri_clicked()
{
    this->close();
}

void ZacetnoOkno::on_do10zmag_clicked()
{

}
