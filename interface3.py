import tkinter as tk
import sys
import os
import libCocktails
import lgpio as sbc

if os.environ.get('DISPLAY','') == '':
    print('no display found. Using :0.0')
    os.environ.__setitem__('DISPLAY', ':0.0')


def testf():
    print("button clicked")



h = sbc.gpiochip_open(0)
x = libCocktails.Cocktails()

root = tk.Tk()

canvas = tk.Canvas(root, height=500, width=1280)
canvas.pack()



def warning(functionName):

    newWindow = tk.Toplevel(root)
    newWindow.title("warning")
    
    canvas = tk.Canvas(newWindow, width=1000, height=1280, bg="black")
    canvas.pack()
    
    frame = tk.Frame(newWindow, bg="white")
    frame.place(relheight=0.5, relwidth=0.5, relx=0.5, rely=0.3, anchor='n')

    label = tk.Label(frame, text="Put the glass on the scale and click continue.")
    label.pack()
    
    button = tk.Button(frame, text="Continue", command=lambda:[functionName(), newWindow.destroy()])
    button.place(relx = 0.4, rely = 0.1, relwidth=0.25, relheight=0.25)

    
    
frame = tk.Frame(root, bg='#80c1ff', bd=5)
frame.place(relx=0.5, rely=0.1, relwidth=0.75, relheight=0.8, anchor='n')



ginTonicButton = tk.Button(frame, text="Gin Tonic", font=70, command=lambda:warning(x.ginTonic))    #test this function call
ginTonicButton.place(relx=0.05, rely=0.1, relwidth=0.25, relheight=0.25)

ginHassButton = tk.Button(frame, text="Gin Hass", font=70, command=x.ginHass)
ginHassButton.place(relx=0.35, rely=0.1, relwidth=0.25, relheight=0.25)

screwdriverButton = tk.Button(frame, text="Screwdriver", font=70, command=x.screwdriver)
screwdriverButton.place(relx=0.65, rely=0.1, relwidth=0.25, relheight=0.25)

blackRussianButton = tk.Button(frame, text="Black Russian", font=70, command=x.blackRussian)
blackRussianButton.place( relx=0.05, rely=0.6, relwidth=0.25, relheight=0.25)

summerCollinsButton = tk.Button(frame, text="Summer Collins", font=70, command=x.summerCollins)
summerCollinsButton.place( relx=0.35, rely=0.6, relwidth=0.25, relheight=0.25)

exitButton = tk.Button(frame, text="Exit", font=70, command=root.destroy)
exitButton.place( relx=0.65, rely=0.6, relwidth=0.25, relheight=0.25)

cleanButton = tk.Button(frame, text="Clean". font=70, command=x.cleanPumps)
#leanButton.place(relx=0.65, rely=0.6, relwidth=0.25, relheight=0.25)

root.attributes('-fullscreen', True)

root.mainloop()
