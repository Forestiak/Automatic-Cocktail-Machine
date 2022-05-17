from datetime import timedelta
from HX711 import *
import lgpio as sbc
import time
import const



def setWeight ():
  hx = AdvancedHX711(const.dataPin, const.clockPin, const.refUnit, const.offset)
  m = hx.weight(15)
  previousWeight = float(m)

  return previousWeight



def checkWeight():
  hx = AdvancedHX711 (const.dataPin, const.clockPin, const.refUnit, const.offset)
  m = hx.weight(timedelta(seconds=0.15))
  weight = float(m)

  print(weight)

  return weight


class Cocktails:

  def prepareDrink (self, firstWeight, secondWeight, firstPumpPin, secondPumpPin):

    weight = 0
    previousWeight = 0
    
    h = sbc.gpiochip_open(0)

    sbc.gpio_claim_output(h, firstPumpPin, 1)
    sbc.gpio_claim_output(h, secondPumpPin, 1)

    print("Put the glass on the scale")
    time.sleep(3)

    print("Calibrating")
    previousWeight = setWeight()

    print("Calibration done. First pump initialized")
    time.sleep(2)

    sbc.gpio_write(h, firstPumpPin, 0)

    while True:
      weight = checkWeight()
      weight -= previousWeight
      print(weight)

      if (weight >= firstWeight):
        sbc.gpio_write(h, firstPumpPin, 1)
        break

    
    time.sleep(2)
    print("Calibrating")
    previousWeight = setWeight()

    print("Calibration done. Second pump initialized")
    time.sleep(2)

    sbc.gpio_write(h, secondPumpPin, 0)

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
    
    
    
    
