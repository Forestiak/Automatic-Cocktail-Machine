#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <hx711/common.h>
#include <lgpio.h>


#define PUMP_GIN_PIN 2
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



double setWeight(){
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double previousWeight = hx.weight(15);

    return previousWeight;
}

double checkWeight() {
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double weight = hx.weight(milliseconds(150));
    //cout << currentWeight << endl;
    return weight;
}



class Cocktails {
    public:

         int prepareDrink(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin){ 

            double weight = 0;
            double previousWeight = 0;
            int hh;

            //claim the pumps as outputs
            hh = lgGpiochipOpen(0);                             
            lgGpioClaimOutput(hh, 0, firstPumpPin, 1); 
            lgGpioClaimOutput(hh, 0, secondPumpPin, 1);      

            //tare the scale with a glass on it
            cout << "Put the glass on the scale" << endl;
            cin.ignore();
            cout << "Calibrating..." << endl;
            previousWeight = setWeight();
            sleep_for(seconds(2));

            //start the gin pump
            lgGpioWrite(hh, firstPumpPin, 1);

            //start the loop in which we are checking for the current weight on the load cell
            for(;;){
                weight = checkWeight(); 
                weight -= previousWeight;                     
                cout << weight << endl;

            //when the weight is >= as we declared, then it stops the pumps
                if (weight >= firstWeight){               
                    lgGpioWrite(hh, firstPumpPin, 0);              
                    break;
                }    
            }
            sleep_for(seconds(2));
            previousWeight = setWeight();
            cout << "Calibrating..." << endl;
            sleep_for(seconds(2));

            lgGpioWrite(hh, secondPumpPin, 1);                     

            for(;;){
                weight = checkWeight();
                weight -= previousWeight;   

                cout << weight << endl;              

                if (weight >= secondWeight){             
                    lgGpioWrite(hh, secondPumpPin, 0);    
                    break;
                }
            }
            cout << "FINISHED" << endl;
            return 0;
        }

        int ginTonic(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin)
            {prepareDrink(firstWeight, secondWeight, firstPumpPin, secondPumpPin);};
        
        int ginHass(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin)
            {prepareDrink(firstWeight, secondWeight, firstPumpPin, secondPumpPin);};

        int screwdriver(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin)
            {prepareDrink(firstWeight, secondWeight, firstPumpPin, secondPumpPin);};

        int blackRussian(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin)
            {prepareDrink(firstWeight, secondWeight, firstPumpPin, secondPumpPin);};

        int summerCollins(const int firstWeight, const int secondWeight, const int firstPumpPin, const int secondPumpPin)
            {prepareDrink(firstWeight, secondWeight, firstPumpPin, secondPumpPin);};

      
       
};


int main(int argc, char **argv){

    
    Cocktails cocktails;
    int hh;
    hh = lgGpiochipOpen(0);

    for(;;)
        cocktails.ginTonic(200, 100, PUMP_GIN_PIN, PUMP_TONIC_PIN);

    return 0;
}
