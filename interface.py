import sys
import tkinter as tk
import os
import libCocktails
import lgpio as sbc
import time


#because of that it is possible to display the GUI on the raspberry's display from SSH terminal

if os.environ.get('DISPLAY','') == '':
    print('no display found. Using :0.0')
    os.environ.__setitem__('DISPLAY', ':0.0')


h = sbc.gpiochip_open(0)
x = libCocktails.Cocktails()

global root
root = tk.Tk()

canvas = tk.Canvas(root, height=500, width=1280)
canvas.pack()


#creates a new window and executes a function given in the parameter

def warning(functionName):

    newWindow = tk.Toplevel(root)
    newWindow.title("Warning!")
    
    canvas = tk.Canvas(newWindow, width=1000, height=1280, bg="black")
    canvas.pack()
    
    frame = tk.Frame(newWindow, bg="80clff", bd=5)
    frame.place(relheight=0.5, relwidth=0.1, relx=0.8, rely=0.75, anchor='n')

    global label
    label = tk.Label(frame, text="Put the glass on the scale and click continue.", font=('Aerial 18')
    label.place(relx=0.5, rely=0.5, anchor='center')
    
    global continueButton                     
    continueButton = tk.Button(frame, text="Continue", command=lambda:[changeLabel(), functionName(), finishLabel(), newWindow.destroy()])       #lambda allows to execute few function within one click of a button
    continueButton.pack(side='top')
                     
    breakButton = tk.Button(frame, text="X", bg='red', command=newWindow.destroy)
    breakButton.place(relx=0.75, rely=0.1, relwidth=0.1, relheight=0.1)
                     
    newWindow.attributes('-fullscreen', True)


#destroys the "Continue" button and changes the text on the label
                     
def changeLabel():
    global continueButton
    continueButton.destroy()
                     
    global label
    label.configure(text="In progress...")
    label.update()
        
        
#changes the text on the label                     
                     
def finishLable():
    global label
    label.configure(text="Completed")
    label.update()
    time.sleep(3)      
    

#destroys the the main window 

def rootDestroy():
    global root
    root.destroy()

    
    
frame = tk.Frame(root, bg='#80c1ff', bd=5)
frame.place(relx=0.5, rely=0.1, relwidth=0.75, relheight=0.8, anchor='n')


ginTonicButton = tk.Button(frame, text="Gin Tonic", font=70, command=lambda:warning(x.ginTonic))    

ginTonicButton.place(relx=0.05, rely=0.1, relwidth=0.25, relheight=0.25)

ginHassButton = tk.Button(frame, text="Gin Hass", font=70, command=lambda:warning(x.ginHass))
ginHassButton.place(relx=0.35, rely=0.1, relwidth=0.25, relheight=0.25)

screwdriverButton = tk.Button(frame, text="Screwdriver", font=70, command=lambda:warning(x.screwdriver))
screwdriverButton.place(relx=0.65, rely=0.1, relwidth=0.25, relheight=0.25)

blackRussianButton = tk.Button(frame, text="Black Russian", font=70, command=lambda:warning(x.blackRussian))
blackRussianButton.place( relx=0.05, rely=0.6, relwidth=0.25, relheight=0.25)

summerCollinsButton = tk.Button(frame, text="Summer Collins", font=70, command=lambda:warning(x.summerCollins))
summerCollinsButton.place( relx=0.35, rely=0.6, relwidth=0.25, relheight=0.25)

exitButton = tk.Button(frame, text="Exit", font=70, command=rootDestroy)
exitButton.place( relx=0.65, rely=0.6, relwidth=0.25, relheight=0.25)

cleanButton = tk.Button(frame, text="Clean". font=70, command=x.cleanPumps)
cleanButton.place(relx=0.35, rely=0.4, relwidth=0.25, relheight=0.25)

root.attributes('-fullscreen', True)

root.mainloop()
