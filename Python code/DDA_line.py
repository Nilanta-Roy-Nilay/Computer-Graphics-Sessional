import matplotlib.pyplot as plt

def dda_line(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1

    # abs ব্যবহার করা হয়েছে
    length = abs(dx) if abs(dx) >= abs(dy) else abs(dy)
    xi = dx / length
    yi = dy / length

    x, y = x1, y1
    xs, ys = [], []
    for _ in range(int(length)+1):
        xs.append(round(x))
        ys.append(round(y))
        x += xi
        y += yi

    plt.plot(xs, ys, marker='o', color='blue')
    plt.axhline(0, color='black')
    plt.axvline(0, color='black')
    plt.gca().set_aspect('equal')
    plt.show()

x1, y1 = map(int, input("Enter first point: ").split())
x2, y2 = map(int, input("Enter second point: ").split())
dda_line(x1, y1, x2, y2)
