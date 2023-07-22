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
    int oldx = posx;
    int oldy = posy;
    do{
        posx = posx+((rand()%3)-1);
        posy = posy+((rand()%3)-1);

        if(posx >= limitx){
            posx = limitx;
        }
        if(posy >= limity){
            posy = limity;
        }

        if(posx < 0){
            posx =0;
        }
        if(posy<0){
            posy = 0;
        }
    }
    while(posx == oldx && posy == oldy);
}
void animal::moveTo(int x, int y){
    if((posx < limitx && posx >0) &&(posy <limity && posy > 0)){
        posx = x;
        posy = y;
        return;
    }
    else
        return;
}   