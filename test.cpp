/*#include <iostream>
#include <wiringPi.h>
//#include <chrono>
//#include <thread>

#define MOTOR 2


int main(int argc, char **argv){
	
	wiringPiSetupGpio();
	
	pinMode(MOTOR, OUTPUT);
	
	
	printf("blalbalba.\n");
	
	while (1){
		digitalWrite(MOTOR,LOW);
		delay(500);
		digitalWrite(MOTOR,HIGH);
		delay(500);
	
	}
}
*/

#include <iostream>
#include <lgpio.h>

#define MOTOR 2

int main (int argc, char **argv){

	int h;
	h = lgGpiochipOpen(0);
	while(1){
		lgGpioClaimOutput(h, 0, MOTOR, 1);
		lgGpioWrite(h, MOTOR, 0);
		}
}	
