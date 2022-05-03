import tkinter as tk

def testf():
    print("button clicked")

root = tk.Tk()

canvas = tk.Canvas(root, height=500, width=1280)
canvas.pack()

# ginTonicImage = tk.PhotoImage(file='gin-and-tonic-drink.png')

frame = tk.Frame(root, bg='#80c1ff', bd=5)
# pobaw się ustawieniami wielkości ramki
frame.place(relx=0.5, rely=0.1, relwidth=0.75, relheight=0.8, anchor='n')

# test guzika
# ginTonicButton2 = tk.Button(frame, image=ginTonicImage, text='GIN TONIC', font=70)
# ginTonicButton2.pack()

ginTonicButton = tk.Button(frame, text="Gin Tonic", font=70, command=testf)
# ginTonicButton.pack()
ginTonicButton.place(relx=0.05, rely=0.1, relwidth=0.25, relheight=0.25)

ginHassButton = tk.Button(frame, text="Gin Hass", font=70)
ginHassButton.place(relx=0.35, rely=0.1, relwidth=0.25, relheight=0.25)

screwdriverButton = tk.Button(frame, text="Screwdriver", font=70)
screwdriverButton.place(relx=0.65, rely=0.1, relwidth=0.25, relheight=0.25)

blackRussianButton = tk.Button(frame, text="BlackRussian", font=70)
blackRussianButton.place( relx=0.1, rely=0.6, relwidth=0.25, relheight=0.25)

summerCollinsButton = tk.Button(frame, text="Summer Collins", font=70)
summerCollinsButton.place( relx=0.6, rely=0.6, relwidth=0.25, relheight=0.25)

root.mainloop()
