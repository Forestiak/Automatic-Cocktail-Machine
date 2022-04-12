class Cocktails {
    public:

        int ginTonic();
        int ginHass();
        int screwdriver();
        int blackRussian();
        int summerCollins();

        int glassWarning();         //it requires compability with the GUI on the touchscreen
};


int Cocktails::ginTonic(){

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


int Cocktails::glassWarning(){   
    std::cout << "Put the glass under the nozzle and click continue" << std::endl;
    return 0;
}
