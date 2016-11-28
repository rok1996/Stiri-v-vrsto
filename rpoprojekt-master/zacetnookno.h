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

private:
  Ui::ZacetnoOkno *ui;
};

#endif // ZACETNOOKNO_H
