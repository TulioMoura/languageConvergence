#include"alerta.h"

int alerta::getPosx(){
    return posx;
}

int alerta::getPosy(){
    return posy;
}

alerta::alerta(int x, int y, int sinal){
    posx = x;
    posy = y;
    sinal = sinal;
}