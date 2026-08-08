import matplotlib.pyplot as plt

def line_equation(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    m = dy / dx if dx != 0 else 0  

    if dx > 0:
        x, y, xend = x1, y1, x2
    else:
        x, y, xend = x2, y2, x1

    c = y - m * x  

    x_points, y_points = [], []

    while True:
        x_points.append(x)
        y_points.append(y)
        if x == xend:
            break
        x += 1
        y = int(m * x + c)

    plt.plot(x_points, y_points, marker='o', color='black')
    plt.show()


x1, y1 = map(int, input("Enter x1 y1: ").split())
x2, y2 = map(int, input("Enter x2 y2: ").split())

line_equation(x1, y1, x2, y2)
