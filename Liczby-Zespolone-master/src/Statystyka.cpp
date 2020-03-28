#include "../inc/Statystyka.hh"
#include "../inc/LZespolona.hh"


void poprawna(Statystyki & st) /* dodanie odpowiedzi porpawnej do statystyki */
{
st.dobre++;
}
void niepoprawna(Statystyki & st) /* dodanie odpowiedzi nieporpawnej do statystyki */
{
st.zle++;
}
double procent_dobrych(Statystyki l) /* obliczenie procentowego wyniku */
{
double proc=l.dobre*100/(l.dobre+l.zle);
return proc;
}
void inicjuj(Statystyki l) /* wyswietlenie statystyk  */
{
cout << "Ilosc poprawnych odpwiedzi: " << l.dobre <<"\n"<< "Ilosc niepoprawnych odpoweidzi: "<< l.zle<<"\n";  
if(l.dobre==0)
{
cout << "Procent poprawnych odpoweidzi wynosi 0%"<<endl;
}
else
{
cout << "Procent poprawnych odpoweidzi wynosi: " << procent_dobrych(l)<<"%"<<endl;
}
}
