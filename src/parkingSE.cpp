       #include <parkingSE.h>
       
        ParkingSE::ParkingSE(int trig, int echo){
            pinMode(trig , OUTPUT);
            pinMode(echo ,INPUT);
            staroMerenje = 100;
            this->echo = echo;
            this->trig = trig;
        }

        void ParkingSE::ocitaj(){
            digitalWrite(trig, LOW);
            delayMicroseconds(2);
            digitalWrite(trig, HIGH);
            delayMicroseconds(10);
            digitalWrite(trig, LOW);

            long duration = pulseIn(echo, HIGH, 6000);
            if(duration == 0) duration = 8000;
            float distance = duration*0.0344/2;

            if((distance + 12 > staroMerenje) && (distance - 12 < staroMerenje)){  
                staroMerenje = distance;  

                if(distance < 8){
                    stanje = UDAR;
                }else if(distance < 30){
                    stanje = BLIZU;
                }else if(distance < 80){
                    stanje = PREPREKA;
                }else{
                    stanje = SIGURNA;
                }
            }else{
                staroMerenje = distance;
                ocitaj();
            }
        }

        udaljenost ParkingSE::getStanje(){
            return stanje;
        }