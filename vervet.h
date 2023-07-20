#include<animal.h>

class vervet : animal{
    private:
        int simboloOuvido;
        float pesosPredadores [10][3];
    public:
        void ouveAlerta(int a);
        void vePredador(int p);     
};