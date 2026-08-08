# dda_line.py
import matplotlib.pyplot as plt
import numpy as np

def dda_line():
    x1 = float(input("Enter first point x1: "))
    y1 = float(input("Enter first point y1: "))
    x2 = float(input("Enter second point x2: "))
    y2 = float(input("Enter second point y2: "))
    
    dx = x2 - x1
    dy = y2 - y1
    length = max(abs(dx), abs(dy))
    
    xi = dx / length
    yi = dy / length
    
    x = x1
    y = y1
    i = 0
    
    x_coords = []
    y_coords = []
    
    while i <= length:
        x_coords.append(round(x))
        y_coords.append(round(y))
        x += xi
        y += yi
        i += 1
        
    plt.figure()
    plt.axhline(0, color='black', linewidth=1)
    plt.axvline(0, color='black', linewidth=1)
    plt.plot(x_coords, y_coords, marker='s', color='black', markersize=5)
    plt.title("DDA Line Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    dda_line()