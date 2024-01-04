//"spis tresci"
//pokemon przeciwnik w walce
#include <iostream>
#include <string>

using namespace std;

class Przeciwnik
{
 public:
	string nazwa; //bulbasaur, squirtle, charmander
//  int cp; //cp - combat power
  int hp; //punkty zycia
  int nr; //numer
  int att; //losowo od 1-10 atak
  Przeciwnik();
  ~Przeciwnik() = default;
  void losowanie();
  void wyglad();
  void walka(string nazw, int hpp, int* wygrana);
  int atak(int tura, string nazw, int* hp);
};
