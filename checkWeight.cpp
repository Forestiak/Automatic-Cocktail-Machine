#include <cstdlib>
#include <iostream>
#include <string>
#include <hx711/common.h>

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
    }

    return EXIT_SUCCESS;

}

int main(int argc, char** argv){

    checkWeight();
}

//hx.setReferenceUnit(-8623); and hx.setOffset(-1048577);
