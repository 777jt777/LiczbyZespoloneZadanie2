#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
using namespace std;




int main(int argc, char **argv)
{


  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;


  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona ans;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
     cout << " Oblicz wyrazenie: ";
     Wyswietl(WyrZ_PytanieTestowe);
     cout << endl;
     cin >> ans;
     cout << "Odpowiedz:";
     cout <<endl;
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}








































