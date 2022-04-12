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
#define refUnit 40241
#define offset -3670017

using namespace std;
using namespace HX711;
using namespace std::this_thread;
using namespace std::chrono;


int checkWeight() {

    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);

    double currentWeight = hx.weight(milliseconds(200));
    cout << currentWeight << endl;

    return currentWeight;
}


class Cocktails {
    public:

        int ginTonic();
        int ginHass();
        int screwdriver();
        int blackRussian();
        int summerCollins();

        int glassWarning();         //it requires compability with the GUI on the touchscreen
};



int main(int argc, char **argv){

    Cocktails cocktails;
    int hh;
    hh = lgGpiochipOpen(0);

    while(1)    
        cocktails.ginTonic();
}


int ginTonic(){

    const int GIN_WEIGHT = 200;                              //add weight
    const int TONIC_WEIGHT = 100;                            //add weight

    const int ginPump {PUMP_GIN_PIN};
    const int tonicPump {PUMP_TONIC_PIN};

    double currentWeight;

    int hh;
    hh = lgGpiochipOpen(0);                             //activates the GPIO pins
    lgGpioClaimOutput(hh, 0, ginPump, 1);               //sets the ginPump as an output

    void zero(Options o = Options());                   //zeros the scale
    lgGpioWrite(hh, ginPump, 1);                        //turns on the ginPump

    for(;;){
        currentWeight = checkWeight();                  //constantly checks the weight on the load cell

        if (currentWeight >= GIN_WEIGHT){               //if the weight on the load cell is equal or higher than the defined value,
            lgGpioWrite(hh, ginPump, 0);                //then it stops the peristaltic pump
            break;
        }    
    }

    void zero (Options o = Options());                  //zeros the scale
    lgGpioWrite(hh, tonicPump, 1);                      //turns on the tonicPump

    for(;;){
        currentWeight = checkWeight();                  //constantly checks the weight on the load cell

        if (currentWeight >= TONIC_WEIGHT){             //if the weight on the load cell is equal or higher than the defined value,
            lgGpioWrite(hh, tonicPump, 0);              //then it stops the peristaltic pump
            break;
        }
    }
    return 0;
}      


int glassWarning(){   
    std::cout << "Put the glass under the nozzle and click continue" << std::endl;
    return 0;
}
