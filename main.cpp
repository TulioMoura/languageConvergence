#define ENV_w = 50
#define ENV_H = 50

#define monkey_count = 10
#define predator_a_count = 2
#define predator_b_count = 2
#define predator_c_count = 2

#define raioPercepcao = 5
#define raioOuvir = 8


//o predador apenas se move aleatoriamente no mapa
//o animal se move aleatoriamente, porém detectando seu redor

//a cada iteração, cada animal se move 1 casa, e verifica se foi disparado algum alerta próximo dele
//existem 2 listas contendo alertas, os alertas atuais e o alerta da próxima iteração.
//um alerta contém sua posição, 