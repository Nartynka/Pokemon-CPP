//pokemon startowy
using namespace std;

class Pokemon
{
private:
	string rodzaj; //wodny, ognisty, lisciasty
	int cp; //cp - combat power
	int iv; //Individual Values (atak, defensywa, hp)
	int nr;//nr pokemona
	int evo; //ewolucja
	int exp; //punkty doswiadczenia
	int hp; //punkty zycia

public:
  Pokemon();
  ~Pokemon() = default;
	string nazwa; //bulbasaur, squirtle, charmander
//	friend class Walka;
	void tworzenie(); // jesli nie to wybiera
	void sprawdz(); //sprawdza czy w pliku jest zadeklarowany pokemon
	void menu();   //jesli tak to wyswietla menu
	void info(); //wyswietla informacje o pokemonie
	void odczyt(); //odczytuje pokemona z pliku
	void zapis(); //zapisuje info o pokemonie do pliku
	//void ewolucja(); //ewolucja
	void walka();
	void wyglad();
	void ewo();
};
