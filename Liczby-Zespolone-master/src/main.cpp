#include <iostream>
#include "../inc/BazaTestu.hh"
#include "../inc/LZespolona.hh"
#include "../inc/WyrazenieZesp.hh"
#include "../inc/Statystyka.hh"
#include <climits>
using namespace std;
/* UWAGA */
/* Wywolanie poziomu trudnosci testu odpbywa sie przez wejscie do katalogu z plikiem i wywolania:
./test_arytm_zesp  trudny
lub
./test_arytm_zesp  latwy
   */










int main(int argc, char **argv)
{



  if (argc < 2) {
    cout << endl;
    cout << " Wybierz poziom trudnosci testu" << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 0;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;



  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona ans;           /* odpoweidz uzytkownika */
  LZespolona wynik;         /* wynik obliczenia wyrazenia zespolonego */
  int i;   
  Statystyki odp;         /* zmienna przechowujaca dane ze struktury */
  odp.dobre=0;           /* Wyzerowanie zmiennych przechowujacych dane odpowiedzi */
  odp.zle=0;                               

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
     cout << " Oblicz wyrazenie: ";
     cout <<(WyrZ_PytanieTestowe)<< " = ";
     cout << endl;
     for(i=0;i<3;i++){
     cout << "Twoja odpowiedz: "; 
     cin >> ans;      /* wczytanie odpoweidzi */
     if(!cin.good())
     {
     cout << endl << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz.\n";
     cin.clear();                    /* wyczyszczenie strumienia */
     cin.ignore(INT_MAX,'\n');       
     }
     else
     break;
     }
     wynik=Oblicz(WyrZ_PytanieTestowe);
     if(ans==wynik)
     {
      cout << ":) Odpowiedz poprawna";
      poprawna(odp); /* dodanie odpowiedzi poprawnej do statystyki */
     }  
     else
     {
       cout << " :( Blad. Prawidlowym wynikiem jest: ";
       cout << wynik;
       niepoprawna(odp);   /* dodanie odpowiedzi niepoprawnej do statystyki */
     }   
     cout <<endl;
  }
  procent_dobrych(odp);     /* obliczenie procentowego wyniku */
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  inicjuj(odp);     /* wyswietlenie statystyk  */
}








































