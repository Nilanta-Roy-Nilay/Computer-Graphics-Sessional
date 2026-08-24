# bresenham_circle.py
import matplotlib.pyplot as plt

def bresenham_circle():
    xc = int(input("Input center of the circle xc: "))
    yc = int(input("Input center of the circle yc: "))
    r = int(input("Input the radius of the circle r: "))
    
    p = 3 - (2 * r)
    x = 0
    y = r
    
    x_coords = []
    y_coords = []
    
    def plot_symmetric_points(xc, yc, x, y):
        points = [
            (xc + x, yc + y), (xc - x, yc + y),
            (xc + x, yc - y), (xc - x, yc - y),
            (xc + y, yc + x), (xc - y, yc + x),
            (xc + y, yc - x), (xc - y, yc - x)
        ]
        for px, py in points:
            x_coords.append(px)
            y_coords.append(py)

    while x <= y:
        plot_symmetric_points(xc, yc, x, y)
        if p < 0:
            x += 1
            p += (4 * x) + 6
        else:
            x += 1
            y -= 1
            p += (4 * (x - y)) + 10
            
    plt.figure()
    plt.axhline(0, color='black', linewidth=1)
    plt.axvline(0, color='black', linewidth=1)
    plt.scatter(x_coords, y_coords, color='black', s=20)
    plt.title("Bresenham's Circle Algorithm")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    bresenham_circle()