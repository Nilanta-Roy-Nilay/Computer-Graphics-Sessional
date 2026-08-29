import matplotlib.pyplot as plt

def bresenham_line(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    p = 2 * dy - dx
    x, y = x1, y1
    xs, ys = [], []
    while x <= x2:
        xs.append(x); ys.append(y)
        x += 1
        if p < 0:
            p += 2 * dy
        else:
            y += 1
            p += 2 * (dy - dx)
    plt.plot(xs, ys, marker='o', color='red')
    plt.show()

x1, y1 = map(int, input("Enter first point: ").split())
x2, y2 = map(int, input("Enter second point: ").split())
bresenham_line(x1, y1, x2, y2)
