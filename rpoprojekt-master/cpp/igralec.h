#ifndef IGRALEC_H
#define IGRALEC_H
#include<QString>

class Igralec
{
private:
  int st;
  QString ime;
  int zmage;
public:
  Igralec();
  Igralec(QString ime, int st);
  Igralec(Igralec &c);
  void zmaga();
  int getSt();
  int getZmage();
  QString getIme();
  ~Igralec();
};

#endif // IGRALEC_H
