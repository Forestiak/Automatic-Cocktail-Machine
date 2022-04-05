#include <iostream>
//#include <wiringPi.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <hx711/common.h>
#include <lgpio.h>

#define PUMP_GIN_PIN 2            //add specific pins to all of them
#define PUMP_TONIC_PIN
#define PUMP_MANGO_PIN
#define PUMP_VODKA_PIN
#define PUMP_ORANGE_PIN
#define PUMP_COFFEE_PIN
#define PUMP_LEMONADE_PIN
#define LOAD_CELL_DATA_PIN 17
#define LOAD_CELL_CLOCK_PIN 27

using namespace std;
using namespace HX711;
using namespace std::this_thread;
using namespace std::chrono;

int checkWeight();
int glassWarning();
class Cocktails;



int checkWeight() {

    using namespace std;
    using namespace HX711;

    const int dataPin = 17;
    const int clockPin = 27;
    const int refUnit = 40241;
    const int offset = -3670017;

    SimpleHX711 hx(dataPin, clockPin, refUnit, offset);

    while(1){

        const Mass m = hx.weight(10);

        cout    << "\t" << m.getValue() << '\n'
                << "\t" << m.toString(Mass::Unit::G) << '\n'
                << endl;

        if(m.getValue()>120)
            break;
        
        sleep_for(seconds(2));      
    }

    return EXIT_SUCCESS;

}



class Cocktails {
    public:

        int ginTonic(){

            #define GIN_WEIGHT  //add weight
            #define TONIC_WEIGHT //add weight

            const int ginPump {PUMP_GIN_PIN};
            const int tonicPump {PUMP_TONIC_PIN};


            //digitalWrite(ginPump, HIGH);

            checkWeight();

            return 0;
        }    
    
};

int glassWarning(){
    
    std::cout << "Put the glass under the nozzle and click continue" << std::endl;

    return 0;
};



int main(int argc, char **argv){

    checkWeight();

    


    return 0;
}

