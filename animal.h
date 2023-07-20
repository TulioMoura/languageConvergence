

class animal{
    private:
        int posx;
        int posy;
    public:
        animal(int x, int y);
        float distancia(int x, int y);
        void moveRandom();
        void moveTo(int x, int y);
};