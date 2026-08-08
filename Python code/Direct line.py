# direct_line.py
import matplotlib.pyplot as plt

def direct_line():
    x1 = float(input("Enter first point x1: "))
    y1 = float(input("Enter first point y1: "))
    x2 = float(input("Enter second point x2: "))
    y2 = float(input("Enter second point y2: "))
    
    m = (y2 - y1) / (x2 - x1)
    c = y1 - (m * x1)
    
    x_coords = []
    y_coords = []
    
    if abs(x2 - x1) >= abs(y2 - y1):
        for x in range(int(min(x1, x2)), int(max(x1, x2)) + 1):
            y = (m * x) + c
            x_coords.append(round(x))
            y_coords.append(round(y))
    else:
        for y in range(int(min(y1, y2)), int(max(y1, y2)) + 1):
            x = (y - c) / m
            x_coords.append(round(x))
            y_coords.append(round(y))
            
    plt.figure()
    plt.axhline(0, color='black', linewidth=1)
    plt.axvline(0, color='black', linewidth=1)
    plt.plot(x_coords, y_coords, marker='s', color='black', markersize=5)
    plt.title("Direct Line Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    direct_line()