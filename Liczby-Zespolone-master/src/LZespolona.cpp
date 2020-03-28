#include "../inc/LZespolona.hh"
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






/* Definicja sprzezenia LZespolonej  */
LZespolona sprzezenie(LZespolona LZ)
{
LZ.im=-LZ.im;
return LZ;
}
/* Definicja operacji modulu liczby zespolonej  */
double modul(LZespolona LZ)
{
double LM;  
LM=sqrt(pow(LZ.re,2)+pow(LZ.im,2));
return LM;
}

/* Definicja dzielenia przez lcizbe rzeczyiwsta  */
LZespolona dzielenie(LZespolona Skl1, double x){
LZespolona Wynik;
if(x!=0){
Wynik.im = Skl1.im/x;
Wynik.re = Skl1.re/x;
}
return Wynik;
}
/* Sprzezenie operatora dodawania  */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/* Sprzezenie operatora odejmowania */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/* Sprzezenie operatora mnozenia */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}
/* Sprzezenie operatora dzielenia */
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

/* Sprzezenie operatora wyjscia */
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
/* Sprzezenie operatora przyrownania */
bool operator == (LZespolona  Skl1,  LZespolona  Skl2){

if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
return true;
else
return false;
}


std::ostream & operator << (std::ostream & strm, const LZespolona & Skl)
{
return strm<<"("<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<"i)";
}    






