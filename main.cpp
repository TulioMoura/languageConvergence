#define ENV_w = 50
#define ENV_H = 50

#define monkey_count = 10
#define predator_a_count = 2
#define predator_b_count = 2
#define predator_c_count = 2

#define raioPercepcao = 5
#define raioOuvir = 8

#include <iostream>
#include <cmath>
#include <vector>

class animal
{

public:
    static int limitx ;
    static int  limity ;
    int posx, posy;


    static void setLimits(int x, int y ){
        limitx = x;
        limity = y;
    }
    animal(int x, int y)
    {
    }

    animal()
    {
    }

    float distanciaAte(int x, int y)
    {
        float distancia = sqrt(pow((posx - x), 2) + pow((posy - y), 2));
        return distancia;
    }

    void moveRandom()
    {
        int oldx = posx;
        int oldy = posy;
        do
        {
            posx = posx + ((rand() % 3) - 1);
            posy = posy + ((rand() % 3) - 1);

            if (posx >= limitx)
            {
                posx = limitx;
            }
            if (posy >= limity)
            {
                posy = limity;
            }

            if (posx < 0)
            {
                posx = 0;
            }
            if (posy < 0)
            {
                posy = 0;
            }
        } while (posx == oldx && posy == oldy);
    }
    void moveTo(int x, int y)
    {
        if ((posx < limitx && posx > 0) && (posy < limity && posy > 0))
        {
            posx = x;
            posy = y;
            return;
        }
        else
            return;
    }

    int getPosx()
    {
        return posx;
    }
    int getPosy()
    {
        return posy;
    }

    void setPosx(int x)
    {
        posx = x;
    }

    void setPosy(int y)
    {
        posy = y;
    }
};

class alerta
{
public:
    int posx, posy;
    int sinal;
    int getPosx()
    {
        return posx;
    }

    int getPosy()
    {
        return posy;
    }

    alerta(int x, int y, int sinal)
    {
        posx = x;
        posy = y;
        sinal = sinal;
    }
};

class predador : public animal
{
public:
    int tipo;
    int getTipo() const
    {
        return tipo;
    }
    predador(int t)
    {
        srand(time(NULL));
        posx = rand() % limitx;
        posy = rand() % limity;
    }
};

class vervet : public animal
{
public:
    std::vector<alerta> *arrayAlertas;
    int simboloOuvido;
    int predadoRecente;
    float pesosPredadores[10][3];

    void processaAlertas()
    {
        for (int i = 0; i < arrayAlertas->capacity(); i++)
        {
            int xalerta = arrayAlertas->at(i).getPosx();
            int yalerta = arrayAlertas->at(i).getPosy();
            float distToAlert = distanciaAte(xalerta, yalerta);
            if (distToAlert < 3)
            {
                std::cout << "Alerta detectado a: " << distToAlert << " unidades de distancia" << std::endl;
            }
        }
    }

    void vePredador(predador p)
    {
        if (distanciaAte(getPosx(), getPosy()) < 5)
        {
            int s = getSignal(p.getTipo());
            alerta a = alerta(getPosx(), getPosy(), s);
            arrayAlertas->push_back(a);
        }
    }

    int getSignal(int p)
    {
        int temp = 0;
        for (int i = 0; i < 10; i++)
        {
            if (pesosPredadores[i] > pesosPredadores[temp])
            {
                temp = i;
            }
        }
        return temp;
    }

    vervet(int x, int y, std::vector<alerta> *a)
    {
        int simboloOuvido = -1;
        arrayAlertas = a;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                pesosPredadores[i][j] = (rand() % 100) / 100;
            }
        }
        setPosx(x);
        setPosy(y);
    }
};
int animal::limitx = 50;
int animal::limity = 50;
int main()
{
    

    predador predador1 = predador(1);
    predador predador2 = predador(2);
    predador predador3 = predador(3);

    while (true)
    {
        system("clear"); // No Windows, use "cls"

        predador1.moveRandom();
        predador2.moveRandom();
        predador3.moveRandom();

        std::cout << "Predador 1 (Tipo " << predador1.getTipo() << "): [" << predador1.posx << ", " << predador1.posy << "]" << std::endl;
        std::cout << "Predador 2 (Tipo " << predador2.getTipo() << "): [" << predador2.posx << ", " << predador2.posy << "]" << std::endl;
        std::cout << "Predador 3 (Tipo " << predador3.getTipo() << "): [" << predador3.posx << ", " << predador3.posy << "]" << std::endl;

        system("sleep 1");
    }

    return 0;
}

// o predador apenas se move aleatoriamente no mapa
// o animal se move aleatoriamente, porém detectando seu redor

// a cada iteração, cada animal se move 1 casa, e verifica se foi disparado algum alerta próximo dele
// existem 2 listas contendo alertas, os alertas atuais e o alerta da próxima iteração.
// um alerta contém sua posição,