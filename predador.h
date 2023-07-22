#include "animal.h"

class predador : public animal {
private:
    int tipo;

public:
    
    void mover();
    int getTipo() const;
    predador(int t);
};