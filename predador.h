#include "animal.h"

class predador : public animal {
private:
    int tipo;

public:
    predador(int t);
    void mover();
    int getTipo() const;
};