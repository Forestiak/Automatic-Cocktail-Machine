#include <iostream>
#include <thread>       //two libraries which are used here to
#include <chrono>       //stops the program for a fixed time
#include "Cocktails2.h"
#include "main.h"


const int PUMP_GIN_PIN = 2;
const int PUMP_TONIC_PIN = 3;
const int PUMP_MANGO_PIN = 4;
const int PUMP_VODKA_PIN = 14;
const int PUMP_ORANGE_PIN = 15;
const int PUMP_COFFEE_PIN = 17;
const int PUMP_LEMONADE_PIN = 18;
const int PUMP_EIGHT_PIN = 27;

const int dataPin = 19;
const int clockPin = 26;
const int refUnit = 228;
const int offset = -148438;

int main(int argc, char **argv){                //argument count and argument vector. They indicate how command line arguments are passed to main() in C and C++.

    
    CocktailsV2 cocktails;
    int hh;
    hh = lgGpiochipOpen(0);

    lgGpioFree (hh, PUMP_GIN_PIN);              //Frees the GPIO at very beginning. It is necessary to do it in order to avoid saving the old pumps configuration 
    lgGpioFree (hh, PUMP_VODKA_PIN);
    lgGpioFree (hh, PUMP_MANGO_PIN);
    lgGpioFree (hh, PUMP_ORANGE_PIN);
    lgGpioFree (hh, PUMP_COFFEE_PIN);
    lgGpioFree (hh, PUMP_TONIC_PIN);
    lgGpioFree (hh, PUMP_EIGHT_PIN);
    lgGpioFree (hh, PUMP_LEMONADE_PIN);

   cocktails.ginHass();
   cocktails.screwdriver();
   cocktails.ginTonic();
   cocktails.summerCollins();
   cocktails.blackRussian();


    return 0;
}
