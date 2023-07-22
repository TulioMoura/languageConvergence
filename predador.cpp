#include "predador.h"
#include <ctime>
#include <cstdlib>



int predador::getTipo() const {
    return tipo;
}
predador::predador(int t) {
    srand(time(NULL));
    posx = rand() % limitx;
    posy = rand() % limity;
}