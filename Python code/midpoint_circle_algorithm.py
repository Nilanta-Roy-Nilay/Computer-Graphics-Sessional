import matplotlib.pyplot as plt

def midpoint_circle(xc, yc, r):
    x = 0
    y = r
    p = 1 - r  
    
    x_points = []
    y_points = []

    def plot_symmetric_points(xc, yc, x, y):
        points = [
            (xc+x, yc+y), (xc-x, yc+y), (xc+x, yc-y), (xc-x, yc-y),
            (xc+y, yc+x), (xc-y, yc+x), (xc+y, yc-x), (xc-y, yc-x)
        ]
        for px, py in points:
            x_points.append(px)
            y_points.append(py)

    plot_symmetric_points(xc, yc, x, y)
    
    while x < y:
        x += 1
        if p < 0:
            p = p + 2 * x + 1
        else:
            y -= 1
            p = p + 2 * (x - y) + 1
        plot_symmetric_points(xc, yc, x, y)
    
    plt.scatter(x_points, y_points, s=1)
    plt.show()

xc = int(input("Enter center x: "))
yc = int(input("Enter center y: "))
r = int(input("Enter radius: "))
midpoint_circle(xc, yc, r)