#ifndef PARKINGIN_H
#define PARKINGIN_H

#include <parkingSE.h>


    class Interfejs{
        private:
            int zelena;
            int zuta1;
            int zuta2;
            int crvena;
            int zvucnik;
            udaljenost daljina;
        
        public:
            Interfejs(int ,int ,int , int, int);
            void azuriraj(udaljenost);
    };

#endif
