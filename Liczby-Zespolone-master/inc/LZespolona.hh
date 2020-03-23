#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
using namespace std;
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
LZespolona utworz(double re , double im );
LZespolona sprzezenie(double re, double im);
void wyswietl(LZespolona LZ);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
std::istream & operator >>(std::istream & strm, LZespolona & Skl);
std::ostream & operator << (std::ostream & strm, const LZespolona & Skl);

#endif
