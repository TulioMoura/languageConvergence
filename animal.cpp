#include<animal.h>
#include <cmath>

animal::animal(int x, int y){

}

animal::animal(){
    
}

float animal::distanciaAte(int x, int y){
    float distancia = sqrt(pow((posx - x), 2)+pow((posy - y), 2));
    return distancia;
}

void animal::moveRandom(){

}
void animal::moveTo(int x, int y){

}