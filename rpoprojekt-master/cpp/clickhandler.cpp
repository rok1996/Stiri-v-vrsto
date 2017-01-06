#include "clickhandler.h"

ClickHandler::ClickHandler(QObject *parent) : QObject(parent)
{
}

//Ta event filter dela samo če event sproži igralno polje, drugače nima funkcijo
bool ClickHandler::eventFilter(QObject *obj, QEvent *event){
  int i = 0, x = 0, y = 0, xs = 0, ys = 0, stv=5, sts=6;
  int ii=0;
  int abc, abc2;
  if(event->type() == QEvent::MouseButtonRelease){
    glavnookno *w = (glavnookno*)this->parent();//referenca na glavno okno, lažji dostop
    QGridLayout *g = w->igP;//referenca na igralno polje
    i = g->indexOf((QWidget *)obj);//obj je tipa QObject*, cast-ovanjem se spremeni v QWidget*
    if(w->ttip==3){
        abc=&stv-&x;
        abc2=&sts-&y;
        g->getItemPosition(i, &abc, &abc2, &xs, &ys);
    }else{
        g->getItemPosition(i, &x, &y, &xs, &ys);
    }
    //g->getItemPosition(i, &x, &y, &xs, &ys);//funkcija prevede indeks v pozicijo elementa v tabeli
    int* addr;
    if(w->ttip==1){
        addr = w->igra->potez(y-1, w->igra->getNaVrsti()->getSt());//klic metode Igra::potez ki preko reference vključene v glavnookno
    }else if(w->ttip==2){
        addr = w->igra2->potez(y-1, w->igra2->getNaVrsti()->getSt());
    }else if(w->ttip==3){
        addr = w->igra3->potez(abc2-1, w->igra3->getNaVrsti()->getSt());
    }
    //int* addr = w->igra->potez(y-1, w->igra->getNaVrsti()->getSt());//klic metode Igra::potez ki preko reference vključene v glavnookno
    if(addr[0] == 1 || addr[0] == 2){//če je potez pravilen, posodobljena različica vrne id igralca
     /**/
        w->setPolje(addr[1], addr[2], addr[0]);//posodobi igralno polje
      if(w->ttip==1){

          if(w->igra->preveriZmaga(addr[1], addr[2], addr[0]))//če obstaja zmagovalec, izpiši ga
          w->zmagovalec(addr[0]);
          else if(w->igra->preveriNeodloceno())//če je nedoločeno, izpiši
            w->zmagovalec(0);
      }else if(w->ttip==2){

          if(w->igra2->preveriZmaga(addr[1], addr[2], addr[0], ii)){//če obstaja zmagovalec, izpiši ga
              for(int i=0;i<ii+1;i++){
                  for(int j=0;j<7;j++){
                      if(w->igra2->polje[i][j]!=0){
                          w->setPolje(i,j,0);
                      }
                  }
              }
              w->zmagovalec2(addr[0]);
         }else if(w->igra2->preveriNeodloceno())//če je neodločeno, izpiši
              w->zmagovalec2(0);
      }else if(w->ttip==3){
          if(w->igra3->preveriZmaga(addr[1], addr[2], addr[0]))//če obstaja zmagovalec, izpiši ga
              w->zmagovalec(addr[0]);
          //w->zmagovalec(addr[0]);
          else if(w->igra3->preveriNeodloceno())//če je nedoločeno, izpiši
            w->zmagovalec(0);
      }


/*
        if(w->igra->preveriZmaga(addr[1], addr[2], addr[0]))//če obstaja zmagovalec, izpiši ga
        w->zmagovalec(addr[0]);*/
      /*
      else if(w->igra->preveriNeodloceno())//če je nedoločeno, izpiši
        w->zmagovalec(0);*/
    } else { //če potez ni pravilen
      w->ilegalMove();
    }
    return true;
  } else {
    return QObject::eventFilter(obj, event);//Na vse druge evente se odzovi na običajen način
  }
}
