#ifndef COCKTAILSV2_H
#define COCKTAILSV2_H

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <hx711/common.h>
#include <lgpio.h>
#include "main.h"

using namespace std;
using namespace HX711;
using namespace std::this_thread;
using namespace std::chrono;

double setWeight(){
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);                                           //allows to use the HX711 library to obtain weight samples from the load cell
    double previousWeight = hx.weight(15);                                                          //takes 15 samples of weight and outputs an average of them

    return previousWeight;
}

double checkWeight() {
    AdvancedHX711 hx(dataPin, clockPin, refUnit, offset);
    double weight = hx.weight(milliseconds(150));
    //cout << weight << endl;
    return weight;
}

class CocktailsV2 {
    public:
        void prepareDrink(int firstWeight, int secondWeight, int firstPumpPin, int secondPumpPin){      //respectfully sets 1. The weight of the first liquid, 2. The weight of the second liquid, 3. Pump which is used to transfer the 1st liquid, 4. Pump which is used for the 2nd liquid

            double weight = 0;                                                                          
            double previousWeight = 0;
            int h;                                                                                      //it is just a user which has to be declared in order to initial the lgpio pins library

            //a shortcut to open the gpiochip device.
            h = lgGpiochipOpen(0);

            //declares given pins as an output and sets them to level 1 - off
            lgGpioClaimOutput (h, 0, firstPumpPin , 1);
            lgGpioClaimOutput (h, 0, secondPumpPin , 1);

            //tare the scale with a glass on it
            cout << "Put the glass on the scale" << endl;
            cin.ignore();                                                                               //stops the program and waits for the "backspace" click to continue
            cout << "Calibrating..." << endl;
            previousWeight = setWeight();                                                               //sets the weight which is currently on the load cell
            cout << "Calibration done. First pump initialized" << endl;
            sleep_for(seconds(1));

            //turns on the first given pump
            lgGpioWrite(h, firstPumpPin, 0);                                                         

            //starts the loop in which we are checking for the current weight on the load cell and subtracting the weight which was on the load cell so far
            for(;;){
                weight = checkWeight(); 
                weight -= previousWeight;                     
                cout << weight << endl;

            //when the weight is >= as we declared, then it stops the pumps
                if (weight >= firstWeight){               
                    lgGpioWrite(h, firstPumpPin, 1);              
                    break;
                }    
            }
            sleep_for(seconds(1));
            cout << "Calibrating..." << endl;
            previousWeight = setWeight();                                                               //sets the weight which is currently on the load cell
            cout << "Calibration done. Second pump initialized" << endl;
            sleep_for(seconds(1));

            //turns on the second given pump
            lgGpioWrite(h, secondPumpPin, 0);                     

            //starts the loop in which we are checking for the current weight on the load cell and subtracting the weight which was on the load cell so far
            for(;;){
                weight = checkWeight();
                weight -= previousWeight;   
                cout << weight << endl;              

            //when the weight is >= as we declared, then it stops the pumps
                if (weight >= secondWeight){             
                    lgGpioWrite(h, secondPumpPin, 1);    
                    break;
                }
            }
            cout << "FINISHED" << endl;
            
            lgGpioFree (h, firstPumpPin);           //Frees the GPIO. It is necessary to do it in order to avoid saving the old pumps configuration 
            lgGpioFree (h, secondPumpPin);          //Frees the GPIO. It is necessary to do it in order to avoid saving the old pumps configuration
        }

        //Functions in which we are specifying particular values
        void screwdriver(){
            prepareDrink(200, 100, PUMP_VODKA_PIN, PUMP_ORANGE_PIN);
        }

        void ginHass(){
            prepareDrink(100, 60, PUMP_GIN_PIN, PUMP_MANGO_PIN);
        }

        void summerCollins(){
            prepareDrink(300, 40, PUMP_GIN_PIN, PUMP_LEMONADE_PIN);
        }

        void blackRussian(){
            prepareDrink(300, 40, PUMP_VODKA_PIN, PUMP_COFFEE_PIN);
        }

        void ginTonic(){
            prepareDrink(300, 40, PUMP_GIN_PIN, PUMP_TONIC_PIN);
        }


};

#endif
