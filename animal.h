

class animal{
    private:
        int posx;
        int posy;
    public:
        animal();
        animal(int x, int y);
        float distanciaAte(int x, int y);
        void moveRandom();
        void moveTo(int x, int y);
};