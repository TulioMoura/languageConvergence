#include "predador.h"
#include <ctime>
#include <cstdlib>

predador::predador(int t) : tipo(t) {
    srand(time(NULL));
    posx = rand() % limitx;
    posy = rand() % limity;
}

int predador::getTipo() const {
    return tipo;
}