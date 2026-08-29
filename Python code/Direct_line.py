import matplotlib.pyplot as plt

def direct_line(x1, y1, x2, y2):
    m = (y2 - y1) / (x2 - x1)
    c = y1 - m * x1
    xs, ys = [], []
    for x in range(x1, x2+1):
        y = round(m * x + c)
        xs.append(x); ys.append(y)
    plt.plot(xs, ys, marker='o', color='blue')
    plt.show()

x1, y1 = map(int, input("Enter first point: ").split())
x2, y2 = map(int, input("Enter second point: ").split())
direct_line(x1, y1, x2, y2)
