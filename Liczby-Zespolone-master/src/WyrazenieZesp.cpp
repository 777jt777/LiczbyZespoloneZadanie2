#include "../inc/WyrazenieZesp.hh"
#include <iostream>
#include "../inc/LZespolona.hh"
using namespace std;


/* oblicza wyrazenie zespolone */
LZespolona Oblicz(WyrazenieZesp  WyrZ) 
{
LZespolona Wynik;
switch(WyrZ.Op)
{
case Op_Dodaj:
Wynik=WyrZ.Arg1 + WyrZ.Arg2;
break;
case Op_Odejmij:
Wynik=WyrZ.Arg1 - WyrZ.Arg2;
break;
case Op_Mnoz:
Wynik=WyrZ.Arg1 * WyrZ.Arg2;
break;
case Op_Dziel:
Wynik=WyrZ.Arg1 / WyrZ.Arg2;
break;
}
return Wynik;
}

/* przeciazenie operatora wyjscia wyrazenia zespoloengo */
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp &WyrZ) 
{

switch(WyrZ.Op)
{
case Op_Dodaj:
cout<<WyrZ.Arg1<<"+"<<WyrZ.Arg2;
break;
case Op_Odejmij:
cout<<WyrZ.Arg1<<"-"<<WyrZ.Arg2;
break;
case Op_Mnoz:
cout<<WyrZ.Arg1<<"*"<<WyrZ.Arg2;
break;
case Op_Dziel:
cout<<WyrZ.Arg1<<"/"<<WyrZ.Arg2;
break;
}
return strm;
}


