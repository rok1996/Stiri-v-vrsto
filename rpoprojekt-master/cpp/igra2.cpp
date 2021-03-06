#include "igra2.h"
#include <QMessageBox>

Igra2::Igra2(): i1(NULL), i2(NULL), polje(NULL), naVrsti(NULL), l(false){}
Igra2::Igra2(Igralec *i1, Igralec *i2){
  //this->i1 = i1;
  //this->i2 = i2;
  this->i1=new Igralec(i1->getIme(),i1->getSt());
  this->i2=new Igralec(i2->getIme(),i2->getSt());
  this->naVrsti = i1;
  this->l = false;
  polje = new int*[6];
  for(int i = 0; i<6; i++){
    polje[i] = new int[7];
  }
  for(int i = 0; i<6; i++)
    for(int j = 0; j<7; j++)
      polje[i][j] = 0;
}

int** Igra2::getPolje(){
  return polje;
}

void Igra2::lock(){//toggle lock
  l = !l;
}

bool Igra2::locked(){
  return l;
}

//igra je neodločena če je polje polno in ni zmagovalca
bool Igra2::preveriNeodloceno(){
  int i = 0;
  for(i = 0; i < 7; i++)
    if(polje[0][i] == 0)
      return false;
  return true;
}

//preverjanje zmagovalca
bool Igra2::preveriZmaga(int x, int y, int p, int &ii){
  int v=0, i = x, j = y;
  int iii=ii;
  bool z = false;
  //vodoravno
  while(i<6 && j<7 && polje[i][j]==p){
    v++;
    j++;
  }
  j = y - 1;
  while(i<6 && j>=0 && polje[i][j]==p){
    v++;
    j--;
  }
  if(v >= 4){
        ii=i;
        z = true;
  }
  //navpično
  v = 0, i = x, j = y;
  while(i<6 && j<7 && polje[i][j]==p){
    v++;
    i++;
  }
  iii=i-1;
  i = x - 1;
  while(i>=0 && j<7 && polje[i][j]==p){
    v++;
    i--;
  }
  if(v >= 4){
      ii=iii;
      z = true;
  }
  //diagonalno 1
  v = 0, i = x, j = y;
  while(i<6 && j<7 && polje[i][j]==p){
    v++;
    i++;
    j++;
  }
  iii=i-1;
  i = x - 1;
  j = y - 1;
  while(i>=0 && j>=0 && polje[i][j]==p){
    v++;
    i--;
    j--;
  }
  if(v >= 4){
      ii=iii;
      z = true;
  }
  //diagonalno 2
  v = 0, i = x, j = y;
  while(i>=0 && j<7 && polje[i][j]==p){
    v++;
    i--;
    j++;
  }
  i = x + 1;
  j = y - 1;
  while(i<6 && j>=0 && polje[i][j]==p){
    v++;
    i++;
    j--;
  }
  if(v >= 4){
      ii=i-1;
      z = true;
  }

  return z;
}

Igralec* Igra2::getNaVrsti(){
  return naVrsti;
}

void Igra2::setNaVrsti(Igralec *n){
  naVrsti = n;
}

int* Igra2::potez(int y, int p){
  int *ret = new int[3], i = 5;
  ret[0] = 0;
  ret[1] = 0;
  ret[2] = 0;
  /*if(p == i1->getSt())//smena se izvede za vsak potez
    naVrsti = i2;
  else
    naVrsti = i1;*/
  if(polje[0][y] != 0)//če je stolpec poln, potez ni pravilen
    ret[0] = -1;
  else{
    while(i>=0){//od spodaj navzgor preverjaj ali je polje prazno
      if(polje[i][y] == 0){//če je, vstavi žeton
        polje[i][y] = p;
        int ii=i;
        int jj=y;
        sklad.push(jj);
        sklad.push(ii);
        ret[0] = p;
        ret[1] = i;
        ret[2] = y;
        moves.push(ret);
        i = 0;
        if(p == i1->getSt())//smena se izvede samo če je potez pravilen
          naVrsti = i2;
        else
          naVrsti = i1;
      }
      i--;
    }
  }
  if(l)//ne dovoli poteza če je igra zaklenjena
  {
      printf("dfbdsfdfd\n");
      ret[0] = -1;
  }
    //ret[0] = -1;
  return ret;
}

int* Igra2::undo2(){
  int *p, *r, x = 0, y = 0;
  r = new int[3];
  r[0] = 0;
  r[1] = 0;
  r[2] = 0;
  if(!l && !moves.empty()){//ne dovoli undo če je igra zaklenjena ali je stack prazen
    p = moves.top();
    moves.pop();
    x = p[1];
    y = p[2];
    polje[x][y] = 0;
    r[1] = x;
    r[2] = y;
    if(p[0] == i1->getSt())//igralec ki zahteva undo je spet na vrsti
      naVrsti = i1;
    else
      naVrsti = i2;
  } else {
    r[0] = -1;
  }
  return r;
}

Igra2::~Igra2(){
  i1 = NULL;
  i2 = NULL;
  naVrsti = NULL;
  if(polje != NULL){
    for(int i = 0; i < 6; i++)
      delete[] polje[i];
    delete[] polje;
    polje = NULL;
  }
}

int Igra2::undo(){
    int a=sklad.top();
    sklad.pop();
    return a;
}

size_t Igra2::velikost(){
    return sklad.size();
}
