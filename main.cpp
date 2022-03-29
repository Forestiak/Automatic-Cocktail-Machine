#include <iostream>
#include <wiringPi.h>
#include <thread>

#define PUMP_GIN_PIN            //add specific pins to all of them
#define PUMP_TONIC_PIN
#define PUMP_MANGO_PIN
#define PUMP_VODKA_PIN
#define PUMP_ORANGE_PIN
#define PUMP_COFFEE_PIN
#define PUMP_LEMONADE_PIN
#define LOAD_CELL_PIN


int main(int argc, int **argv){

    wiringPiSetupGpio();
    pinMode(LOAD_CELL,INPUT);
    pinMode(PUMP_GIN, OUTPUT);


    while(1){

    }

}


