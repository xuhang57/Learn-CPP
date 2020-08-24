class Nerd
{
    public:
        void init() {
            myStinkiness = 0;
            myIQ = 100;
        }

        void study(int hours) {
            myStinkiness += 3*hours;
        }

        int getStinkyLevel() {
            int total_stink = myIQ * 10 + myStinkiness;
            return total_stink;
        }
    private:
        int myStinkiness, myIQ;
};