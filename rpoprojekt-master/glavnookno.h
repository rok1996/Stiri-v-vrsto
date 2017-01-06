#ifndef GLAVNOOKNO_H
#define GLAVNOOKNO_H

#include <QMainWindow>
#include <QMessageBox>
//Includes for game logic
#include "cpp/igra.h"
#include "cpp/igra2.h"
#include "cpp/igra3.h"
//handler
#include <QEvent>
#include "cpp/clickhandler.h"
//includes for UI
#include "ui_izpis_zmagovalca.h"
#include "ui_izpis_neodloceno.h"
#include "ui_vnosimena1.h"
#include "ui_vnosimena2.h"
#include <QString>
#include <QInputDialog>
#include <QApplication>
#include <QWidget>
#include <QLabel>
//timer
#include <QTime>
#include <QTimer>
#include <QObject>
//music
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
  class glavnookno;
}

class glavnookno : public QMainWindow
{
  Q_OBJECT

public:
  explicit glavnookno(QWidget *parent = 0);
  void vnosImen();
  void zmagovalec(int);
  void zmagovalec2(int);
  void setPolje(int x, int y, int i);
  void clearPolje();
  void potez(int x, int y);
  void updateUi();
  void ilegalMove();
  Igra *igra;
  Igra2 *igra2;
  Igra3 *igra3;
  QGridLayout *igP;
  QPushButton *volume;
  int ttip;
  ~glavnookno();

private slots:
  //void about();
  void on_undo_clicked();
  void undo2();
  //timer
  void izpiscas();
  //background music
  //void toggleMusic();

public slots:
  void start();
  void setMusic();
private:
  Ui::glavnookno *ui;
  Igralec *i1, *i2;
  class ClickHandler *ch;
  QLabel *statusLabel;
  //timer:
  QTimer *timer;
  QTime *cas;
  Igralec *z;
  //background music
  bool music = true;
  QMediaPlayer *mPlayer;
  QMediaPlaylist *playlist;
};

#endif // GLAVNOOKNO_H
