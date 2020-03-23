#include "WyrazenieZesp.hh"
#include <iostream>
#include "LZespolona.hh"
using namespace std;

void Wyswietl(WyrazenieZesp  WyrZ)
{
wyswietl(WyrZ.Arg1);
switch(WyrZ.Op)
{
case Op_Dodaj:
cout<<"+";
break;
case Op_Odejmij:
cout<<"-";
break;
case Op_Mnoz:
cout<<"*";
break;
case Op_Dziel:
cout<<"/";
break;
}
wyswietl(WyrZ.Arg2);

}

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


std::ostream & operator << (std::ostream & strm, const WyrazenieZesp &WyrZ)
{

switch(WyrZ.Op)
{
case Op_Dodaj:
strm<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)"
<<"+"<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)\n";
break;
case Op_Odejmij:
strm<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)"<<"-"
<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)\n";
break;
case Op_Mnoz:
strm<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)"<<"*"
<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)\n";;
break;
case Op_Dziel:
strm<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)"<<"/"
<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)\n";
break;
}
return strm;
}






/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
