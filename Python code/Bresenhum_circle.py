import matplotlib.pyplot as plt

xc = int(input("Enter the value of xc: "))
yc = int(input("Enter the value of yc: "))
r = int(input("Enter the value of radius: "))

x = 0
y = r
p = 3 - 2 * r

x_point = []
y_point = []

while x <= y:

  
    x_point.append(xc + x)
    y_point.append(yc + y)

    x_point.append(xc + y)
    y_point.append(yc + x)

    x_point.append(xc + x)
    y_point.append(yc - y)

    x_point.append(xc + y)
    y_point.append(yc - x)

    x_point.append(xc - x)
    y_point.append(yc - y)

    x_point.append(xc - y)
    y_point.append(yc - x)

    x_point.append(xc - x)
    y_point.append(yc + y)

    x_point.append(xc - y)
    y_point.append(yc + x)

    if p < 0:
        x = x + 1
        p = p + 4 * x + 6
    else:
        x = x + 1
        y = y - 1
        p = p + 4 * (x - y) + 10

plt.scatter(x_point, y_point, color='blue')
plt.gca().set_aspect('equal')
plt.grid(True)
plt.show()
