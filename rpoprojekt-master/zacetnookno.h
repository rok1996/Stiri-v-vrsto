#ifndef ZACETNOOKNO_H
#define ZACETNOOKNO_H

#include <QDialog>

namespace Ui {
  class ZacetnoOkno;
}

class ZacetnoOkno : public QDialog
{
  Q_OBJECT

public:
  explicit ZacetnoOkno(QWidget *parent = 0);
  ~ZacetnoOkno();
    int tip=0;

/*public slots:
    void onKlik();*/

private slots:
    void on_btnZacni_clicked();

    void on_btnNaGlavo_clicked();

    void on_pushButton_clicked();

    void on_btnZapri_clicked();

    void on_do10zmag_clicked();

private:
  Ui::ZacetnoOkno *ui;
};

#endif // ZACETNOOKNO_H
