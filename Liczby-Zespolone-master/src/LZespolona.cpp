#include "LZespolona.hh"
#include <iostream>
#include<math.h>
using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */





LZespolona utworz(double re, double im)
{
LZespolona LZ;
LZ.re=re;
LZ.im=im;
return LZ;
}

void wyswietl(LZespolona LZ)
{
cout<<"("<<LZ.re<<std::showpos<<LZ.im<<std::noshowpos<<"i)";

}

LZespolona sprzezenie(LZespolona LZ)
{
LZ.im=-LZ.im;
return LZ;
}

double modul(LZespolona LZ)
{
double LM;  
LM=sqrt(pow(LZ.re,2)+pow(LZ.im,2));
return LM;
}
LZespolona dzielenie(LZespolona Skl1, double x){
LZespolona Wynik;
Wynik.im = Skl1.im/x;
Wynik.re = Skl1.re/x;
return Wynik;
}
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  LZespolona Ls1= sprzezenie(Skl2);
  double Lmod= modul(Skl2);
  Lmod=pow(Lmod,2);
  LZespolona a= Skl1 * Ls1;
  Wynik=dzielenie(a,Lmod);
  return Wynik;
}




std::istream & operator >>(std::istream & strm, LZespolona & Skl)
{
  char znak;
  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit); 
  strm>>Skl.re>>Skl.im>>znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit); 
  strm>>znak;
  if (znak != ')'){
    strm.setstate(std::ios::failbit); 
  }
    return strm;
}



std::ostream & operator << (std::ostream & strm, const LZespolona & Skl)
{
return strm<<"("<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<"i\n";
}    






