

class animal{
    private:
        static int limitx;
        static int limity;
        int posx;
        int posy;
    public:
        animal();
        animal(int x, int y);
        float distanciaAte(int x, int y);
        void moveRandom();
        void moveTo(int x, int y);
        int getPosx();
        int getPosy();
        void setPosx(int x);
        void setPosy(int y);
};