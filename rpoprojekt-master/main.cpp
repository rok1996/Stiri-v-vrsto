//Authomatic includes
#include "glavnookno.h"
#include <QApplication>
//Includes for start screen
#include "zacetnookno.h"
#include "ui_zacetnookno.h"
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  glavnookno w;
  w.setVisible(false);
  QDialog* d = new QDialog(0,0);
  Ui_ZacetnoOkno zUi;
  zUi.setupUi(d);
  QMediaPlaylist *playlist = new QMediaPlaylist();
  playlist->addMedia(QUrl("qrc:/audio/audio/music.wav"));
  playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
  QMediaPlayer *music = new QMediaPlayer();
  music->setPlaylist(playlist);
  music->play();
  int s = d->exec(), st = 0;
  if(s == QDialog::Rejected){
    a.exit(0);
  } else if (s == QDialog::Accepted){
    w.show();
    w.start();
    st = a.exec();
  }
  return st;
}
