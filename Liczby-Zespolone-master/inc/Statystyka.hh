#include "BazaTestu.hh"
#include <iostream>

struct Statystyki{
int dobre;
int zle;
};

void inicjuj(Statystyki l);
void poprawna(Statystyki & st);
void niepoprawna(Statystyki & st);
double procent_dobrych(Statystyki l);
