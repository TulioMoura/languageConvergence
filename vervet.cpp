#include<vervet.h>
#include"predador.h"
#include"alerta.h"
#include<cmath>

void vervet::ouveAlerta(int a){

}
void vervet::vePredador(predador p){
    if(distanciaAte(getPosx(), getPosy()) < 5){
        int s = getSignal(p.getType());
        alerta a = alerta(getPosx(),getPosy(),s);
        arrayAlertas->push_back(a);
    }
}

int vervet::getSignal(int p){
    int temp = 0;
    for(int i = 0; i<10;i++){
        if(pesosPredadores[i] > pesosPredadores[temp]){
            temp = i ;
        }
        
    }
}

vervet::vervet(int x, int y, std::vector<alerta> * a){
    int simboloOuvido = -1;
    arrayAlertas = a;
    for(int i = 0; i< 3; i++){
        for(int j =0; j< 10; j++){
            pesosPredadores[i][j] = (rand() % 100)/100;
        }
    }
    setPosx(x);
    setPosy(y);

}