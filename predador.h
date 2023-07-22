#include<animal.h>

class predador : animal{
    private:
        int tipo;
    public:
        predador(int tipo, int x, int y);
        int getType();
};