       #include <parkingSE.h>
       
        ParkingSE::ParkingSE(int trig, int echo){
            pinMode(trig , OUTPUT);
            pinMode(echo ,INPUT);
            staroMerenje = 100;
            this->echo = echo;
            this->trig = trig;
        }

        void ParkingSE::ocitaj(){

            long duration;
            float distance;

            int firstPass = 0;

            do{
            firstPass++;
            digitalWrite(trig, LOW);
            delayMicroseconds(50);
            digitalWrite(trig, HIGH);
            delayMicroseconds(10);
            digitalWrite(trig, LOW);

            duration = pulseIn(echo, HIGH, 6000);
            if(duration == 0) duration = 6000;
            distance = duration*0.0344/2;

            }while((duration == 6000) && firstPass < 2);

            if((distance + 8 > staroMerenje) && (distance - 8 < staroMerenje)){  
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