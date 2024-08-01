// myFunctions.h
#ifndef PARKINGSE_H
#define PARKINGSE_H

#include <NewPing.h>

enum udaljenost{
    SIGURNA,
    PREPREKA,
    BLIZU,
    UDAR
};

class ParkingSE{
    private:
        NewPing* sonar;
        udaljenost stanje;
        int echo, trig;
        int staroMerenje;

    public:

            ParkingSE(int triger, int echo);
            void ocitaj();
            udaljenost getStanje();

};

#endif
