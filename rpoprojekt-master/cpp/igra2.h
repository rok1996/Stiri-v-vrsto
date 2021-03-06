#ifndef IGRA2_H
#define IGRA2_H
#include "igralec.h"
#include <QMessageBox>
#include <stack>
//razred igra neodvisten od grafičnega vmesnika
//#include "glavnookno.h" je problem ker je glavnookno vključeno v igro pred da je definirano
//in igra.h vključen v glavnookno pred da je definiran - paradoks

using namespace std;

class Igra2
{
private:
  Igralec *i1, *i2, *naVrsti;
  //int** polje;
  bool l;
  stack<int*> moves;
public:
  int** polje;
  Igra2();
  Igra2(Igralec *i1, Igralec *i2);
  int** getPolje();
  void setNaVrsti(Igralec *n);
  Igralec *getNaVrsti();
  void lock();
  bool locked();
  int *potez(int y, int p);
  int *undo2();
  bool preveriNeodloceno();
  bool preveriZmaga(int x, int y, int p, int &ii);
  /*bool preveriVodoravno(int x, int y, int p);
  void preveriNavpicno(int y, int p);
  void preveriDiagonalo1(int y, int p);
  void preveriDiagonalo2(int y, int p);*/
  ~Igra2();
  int undo();
  size_t velikost();
  std::stack<int> sklad;
};

#endif // IGRA2_H
