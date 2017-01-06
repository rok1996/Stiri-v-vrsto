#include "igra.h"

Igra::Igra(): i1(NULL), i2(NULL), polje(NULL), naVrsti(NULL), l(false){}
Igra::Igra(Igralec *i1, Igralec *i2){
  this->i1 = i1;
  this->i2 = i2;
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

int** Igra::getPolje(){
  return polje;
}

void Igra::lock(){//toggle lock
  l = !l;
}

bool Igra::locked(){
  return l;
}

//igra je neodločena če je polje polno in ni zmagovalca
bool Igra::preveriNeodloceno(){
  int i = 0;
  for(i = 0; i < 7; i++)
    if(polje[0][i] == 0)
      return false;
  return true;
}

//preverjanje zmagovalca
bool Igra::preveriZmaga(int x, int y, int p){
  int v=0, i = x, j = y;
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
  if(v >= 4)
    z = true;
  //navpično
  v = 0, i = x, j = y;
  while(i<6 && j<7 && polje[i][j]==p){
    v++;
    i++;
  }
  i = x - 1;
  while(i>=0 && j<7 && polje[i][j]==p){
    v++;
    i--;
  }
  if(v >= 4)
    z = true;
  //diagonalno 1
  v = 0, i = x, j = y;
  while(i<6 && j<7 && polje[i][j]==p){
    v++;
    i++;
    j++;
  }
  i = x - 1;
  j = y - 1;
  while(i>=0 && j>=0 && polje[i][j]==p){
    v++;
    i--;
    j--;
  }
  if(v >= 4)
    z = true;
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
  if(v >= 4)
    z = true;

  return z;
}

/*
//preverjanje zmagovalca vodoravno
bool Igra::preveriVodoravno(int y, int p){
    if(p==i1->getSt()){
        v = i1->getSt();
    }
    else{
        v = i2->getSt();
    }
    for(int i=0;i<4;i++){
        if(polje[i][y]!=v){
            return false;
        }
        else{
            return true;
        }

    }
}

//preverjanje zmagovalca navpično
bool Igra::preveriNavpicno(int y, int p){
    int v;
    if(p==i1->getSt()){
        v = i1->getSt();
    }
    else{
        v = i2->getSt();
    }
    for(int i=0;i<4;i++){
        if(polje[y][i]!=v){
            return false;
        }
        else{
            return true;
        }

    }
}

//preverjanje zmagovalca po diagonali
bool Igra::preveriDiagonalo1(int y, int p){
    int v;
    if(p==i1->getSt()){
        v = i1->getSt();
    }
    else{
        v = i2->getSt();
    }
    for(int i=0;i<4;i++){
        if(polje[i][y+i]!=v){
            return false;
        }
        else{
            return true;
        }

    }
}

//preverjanje zmagovalca po diagonali
bool Igra::preveriDiagonalo2(int y, int p){
    int v;
    if(p==i1->getSt()){
        v = i1->getSt();
    }
    else{
        v = i2->getSt();
    }
    for(int i=0;i<4;i++){
        if(polje[i][y-i]!=v){
            return false;
        }
        else{
            return true;
        }

    }
}
*/
Igralec* Igra::getNaVrsti(){
  return naVrsti;
}

void Igra::setNaVrsti(Igralec *n){
  naVrsti = n;
}

int* Igra::potez(int y, int p){
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
    ret[0] = -1;
  return ret;
}

int* Igra::undo2(){
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

Igra::~Igra(){
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

int Igra::undo(){
    int a=sklad.top();
    sklad.pop();
    return a;
}

size_t Igra::velikost(){
    return sklad.size();
}
