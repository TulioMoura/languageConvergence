#include<animal.h>
#include<vector>
class vervet : animal{
    private:
        std::vector <alerta> * arrayAlertas;
        int simboloOuvido;
        int predadoRecente;
        float pesosPredadores [10][3];
    public:
        void processaAlertas();
        void vePredador(predador p);
        vervet(int x, int y,std::vector<alerta>* a);     
        int getSignal(int p);
};