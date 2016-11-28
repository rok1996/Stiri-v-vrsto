#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

#include <QObject>
#include <QEvent>
#include <QGridLayout>
#include <glavnookno.h>
//clickhandler se "pogovarja" direktno in samo z glavnim oknom, ni treba vključevati igra.h

class ClickHandler : public QObject
{
  Q_OBJECT
private:
protected:
  bool eventFilter(QObject *obj, QEvent *event);
public:
  explicit ClickHandler(QObject *parent = 0);
signals:

public slots:
};

#endif // CLICKHANDLER_H
