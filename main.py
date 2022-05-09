import libCocktails
import lgpio as sbc


h = sbc.gpiochip_open(0)
x = libCocktails.Cocktails()

while True:

  x.screwdriver()
  x.blackRussian()
  x.summerCollins()
  x.ginHass()
  x.ginTonic()
