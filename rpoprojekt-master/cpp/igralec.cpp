#include "igralec.h"

Igralec::Igralec(): ime(""), st(0), zmage(0){}
Igralec::Igralec(QString ime, int st):ime(ime), st(st), zmage(0){}
Igralec::Igralec(Igralec &c):ime(c.ime), st(c.st), zmage(c.zmage){}

void Igralec::zmaga(){
  zmage++;
}

int Igralec::getZmage(){
  return zmage;
}

QString Igralec::getIme(){
  return ime;
}

int Igralec::getSt(){
  return st;
}

Igralec::~Igralec(){
  st = 0;
  zmage = 0;
  ime = "";
}
