#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <hx711/common.h>
#include <lgpio.h>

#define PUMP_GIN_PIN 2            //add specific pins to all of them
#define PUMP_TONIC_PIN 3
#define PUMP_MANGO_PIN
#define PUMP_VODKA_PIN
#define PUMP_ORANGE_PIN
#define PUMP_COFFEE_PIN
#define PUMP_LEMONADE_PIN

#define dataPin 17
#define clockPin 27
#define refUnit 234
#define offset -148699

using namespace std;
using namespace HX711;
using namespace std::this_thread;
using namespace std::chrono;


double setCurrentWeight(){
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double currentWeight = hx.weight(15);

    return currentWeight;
}


double setGlassWeight(){
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double glassWeight = hx.weight(15);

    return glassWeight;
}

double checkWeight() {
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double weight = hx.weight(milliseconds(150));
    //cout << currentWeight << endl;
    return weight;
}



class Cocktails {
    public:
        //int ginTonic();
        int ginHass();
        int screwdriver();
        int blackRussian();
        int summerCollins();
      
        int ginTonic(){

            const int GIN_WEIGHT = 200;                              
            const int TONIC_WEIGHT = 100;                            
            const int ginPump {PUMP_GIN_PIN};
            const int tonicPump {PUMP_TONIC_PIN};

            double weight = 0;
            double currentWeight = 0;
            double newWeight = 0;
            double glassWeight = 0;
            double glassAndLiquidWeight = 0;
            int hh;

            hh = lgGpiochipOpen(0);                             
            lgGpioClaimOutput(hh, 0, ginPump, 1);       


            //tare the scale with a glass on it
            cout << "Put the glass on the scale" << endl;
            cin.ignore();
            cout << "Calibrating..." << endl;
            glassWeight = setGlassWeight();
            sleep_for(seconds(2));

            //start the gin pump
            lgGpioWrite(hh, ginPump, 1);

            for(;;){
                weight = checkWeight(); 
                weight -= glassWeight;                     
                cout << weight << endl;

                if (weight >= GIN_WEIGHT){               
                    lgGpioWrite(hh, ginPump, 0);              
                    break;
                }    
            }
            sleep_for(seconds(2));
            glassAndLiquidWeight = setCurrentWeight();
            cout << "Calibrating..." << endl;
            sleep_for(seconds(2));


            lgGpioWrite(hh, tonicPump, 1);                     

            for(;;){
                weight = checkWeight();
                weight -= glassAndLiquidWeight;   

                cout << weight << endl;              

                if (weight >= TONIC_WEIGHT){             
                    lgGpioWrite(hh, tonicPump, 0);    
      
                    break;
                }
            }
            cout << "FINISHED" << endl;
            return 0;
        }
};


int main(int argc, char **argv){

    
    Cocktails cocktails;
    int hh;
    hh = lgGpiochipOpen(0);

      
    //cocktails.ginTonic();

    for(;;)
        cocktails.ginTonic();


    return 0;
}
