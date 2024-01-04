/*
Po uruchomieniu programu:
1. Tworzy obiekt dla ktorego sprawdza czy w pliku tekstowym jest juz zadeklarowany
    pokemon startowy (true/false)
2a. jezli tak to odczytuje go z pliku i nadaje na podstawie tego atrybuty temu obiektowy
    2b. wyswietla menu

3a. jezli nie to poprosi o wybranie pokemona startowego (squirtle, bulba, charmander)
    3b. Losuje i przypisuje atrybuty do obiektu
    3c. zapisuje je w pliku
    3d. wyswietla menu
*/
#include <iostream>
#include "pokemon.h"
#include <windows.h>
using namespace std;

int main()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
  Pokemon pok;
  pok.sprawdz();
  return 0;
}
