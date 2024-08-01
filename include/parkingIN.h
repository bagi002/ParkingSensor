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
            char zvuk[4][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
            };
        
        public:
            Interfejs(int ,int ,int , int, int);
            void azuriraj(udaljenost);
            void sviraj(int);
    };

#endif
