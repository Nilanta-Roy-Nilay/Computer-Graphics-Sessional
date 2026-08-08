import matplotlib.pyplot as plt

def bresenham_circle(xc, yc, r):
    x, y = 0, r
    d = 3 - 2 * r
    x_points, y_points = [], []

    def plot_points(xc, yc, x, y):
        for px, py in [(xc+x, yc+y), (xc-x, yc+y), (xc+x, yc-y), (xc-x, yc-y),
                       (xc+y, yc+x), (xc-y, yc+x), (xc+y, yc-x), (xc-y, yc-x)]:
            x_points.append(px)
            y_points.append(py)

    while y >= x:
        plot_points(xc, yc, x, y)
        x += 1
        if d > 0:
            y -= 1
            d = d + 4 * (x - y) + 10
        else:
            d = d + 4 * x + 6
            
    plt.scatter(x_points, y_points)
    plt.show()

xc = int(input("Enter center x: "))
yc = int(input("Enter center y: "))
r = int(input("Enter radius: "))
bresenham_circle(xc, yc, r)
    