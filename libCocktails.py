from datetime import timedelta
from HX711 import *
import lgpio as sbc
import time
import const


#sets the weight which is currently on the scale

def setWeight ():
  hx = AdvancedHX711(const.dataPin, const.clockPin, const.refUnit, const.offset)
  m = hx.weight(15)
  previousWeight = float(m)

  return previousWeight


#checks the weight which is currently on the scale

def checkWeight():

  hx = AdvancedHX711 (const.dataPin, const.clockPin, const.refUnit, const.offset)
  m = hx.weight(timedelta(seconds=0.15))
  weight = float(m)

  return weight


class Cocktails:

  #prepares a particular cocktail depending on given parameters
  
  def prepareDrink (self, firstWeight, secondWeight, firstPumpPin, secondPumpPin):

    weight = 0
    previousWeight = 0
   
    #opens gpiochip in order to declare and manipulate GPIO Pins 
    h = sbc.gpiochip_open(0)


    #claims the given pins as output
    
    sbc.gpio_claim_output(h, firstPumpPin, 1)
    sbc.gpio_claim_output(h, secondPumpPin, 1)

    print("Put the glass on the scale")
    
    
    #sets the current weight which is on the scale
    
    print("Calibrating")
    previousWeight = setWeight()

    print("Calibration done. First pump initialized")
    time.sleep(2)

    sbc.gpio_write(h, firstPumpPin, 0)


    #tares the weight on the load cell to get the weight without a glass on it
    
    while True:
      weight = checkWeight()
      weight -= previousWeight
      print(weight)

      if (weight >= firstWeight):
        sbc.gpio_write(h, firstPumpPin, 1)
        break
        
      time.sleep(2)
    
    #sets the current weight which is on the scale
    print("Calibrating")
    previousWeight = setWeight()

    print("Calibration done. Second pump initialized")
    time.sleep(2)

    sbc.gpio_write(h, secondPumpPin, 0)


    #tares the weight on the load cell to get the weight without a glass and first liquid on the scale
    
    while True:
      weight = checkWeight()
      weight -= previousWeight
      print(weight)

      if (weight >= secondWeight):
        sbc.gpio_write(h, secondPumpPin, 1)
        break

    sbc.gpio_free(h, firstPumpPin)
    sbc.gpio_free(h, secondPumpPin)

    print("FINISHED")



#5 predefined drinks with given parameters taken from constans.py library

  def screwdriver(self):
    self.prepareDrink(const.VODKA_WEIGHT_SCREWDRIVER, const.ORANGE_WEIGHT, const.PUMP_VODKA_PIN, const.PUMP_ORANGE_PIN)
  
  

  def ginHass(self):
    self.prepareDrink(const.GIN_WEIGHT_GINHASS, const.MANGO_WEIGHT, const.PUMP_GIN_PIN, const.PUMP_MANGO_PIN)



  def ginTonic(self):
    self.prepareDrink(const.GIN_WEIGHT_GINTONIC, const.TONIC_WEIGHT_GINTONIC, const.PUMP_GIN_PIN, const.PUMP_TONIC_PIN)



  def summerCollins(self):
    self.prepareDrink(const.GIN_WEIGHT_SUMMERCOLLINS, const.LEMONADE_WEIGHT, const.PUMP_GIN_PIN, const.PUMP_LEMONADE_PIN)



  def blackRussian(self):
    self.prepareDrink(const.VODKA_WEIGHT_BLACKRUSSIAN, const.COFFEE_WEIGHT, const.PUMP_VODKA_PIN, const.PUMP_COFFEE_PIN)
    
    
  #activates all the pumps for 30sec in order to clean them    
  def cleanPumps()
    h = sbc.gpiochip_open(0)
    
    sbc.gpio_claim_output(h, PUMP_GIN_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_VODKA_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_MANGO_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_ORANGE_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_COFFEE_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_EIGHT_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_TONIC_PIN, 0)
    sbc.gpio_claim_output(h, PUMP_LEMONADE_PIN, 0)
   
    time.sleep(30)
    
    sbc.gpio_write(h, PUMP_GIN_PIN, 1)
    sbc.gpio_write(h, PUMP_VODKA_PIN, 1)
    sbc.gpio_write(h, PUMP_MANGO_PIN, 1)
    sbc.gpio_write(h, PUMP_ORANGE_PIN, 1)
    sbc.gpio_write(h, PUMP_COFFEE_PIN, 1)
    sbc.gpio_write(h, PUMP_LEMONADE_PIN, 1)
    sbc.gpio_write(h, PUMP_EIGHT_PIN, 1)
    sbc.gpio_write(h, PUMP_TONIC_PIN, 1)
    
    sbc.gpio_free(h, PUMP_VODKA_PIN)
    sbc.gpio_free(h, PUMP_GIN_PIN)
    sbc.gpio_free(h, PUMP_MANGO_PIN)
    sbc.gpio_free(h, PUMP_ORANGE_PIN)
    sbc.gpio_free(h, PUMP_COFFEE_PIN)
    sbc.gpio_free(h, PUMP_LEMONADE_PIN)
    sbc.gpio_free(h, PUMP_EIGHT_PIN)
    sbc.gpio_free(h, PUMP_TONIC_PIN)
