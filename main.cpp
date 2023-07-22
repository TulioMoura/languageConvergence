#define ENV_w = 50
#define ENV_H = 50

#define monkey_count = 10
#define predator_a_count = 2
#define predator_b_count = 2
#define predator_c_count = 2

#define raioPercepcao = 5
#define raioOuvir = 8

#include <iostream>
#include "predador.h"

int main() {
    predador predador1 = predador(1);
    predador predador2 = predador(2);
    predador predador3 = predador(3);

    while (true) {
        system("clear"); // No Windows, use "cls"

        predador1.mover();
        predador2.mover();
        predador3.mover();

        std::cout << "Predador 1 (Tipo " << predador1.getTipo() << "): [" << predador1.posx << ", " << predador1.posy << "]" << std::endl;
        std::cout << "Predador 2 (Tipo " << predador2.getTipo() << "): [" << predador2.posx << ", " << predador2.posy << "]" << std::endl;
        std::cout << "Predador 3 (Tipo " << predador3.getTipo() << "): [" << predador3.posx << ", " << predador3.posy << "]" << std::endl;

        system("sleep 1");
    }

    return 0;
}

//o predador apenas se move aleatoriamente no mapa
//o animal se move aleatoriamente, porém detectando seu redor

//a cada iteração, cada animal se move 1 casa, e verifica se foi disparado algum alerta próximo dele
//existem 2 listas contendo alertas, os alertas atuais e o alerta da próxima iteração.
//um alerta contém sua posição, 