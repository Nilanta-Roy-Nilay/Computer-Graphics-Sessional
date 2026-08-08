import matplotlib.pyplot as plt

def bresenham_line(x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    p = 2 * dy - dx
    
    x, y = x1, y1
    x_points, y_points = [x], [y]
    
    while x < x2:
        x += 1
        if p < 0:
            p += 2 * dy
        else:
            y += 1
            p += 2 * dy - 2 * dx
        x_points.append(x)
        y_points.append(y)
        
    plt.plot(x_points, y_points, marker='o')
    plt.show()

x1, y1 = map(int, input("Enter x1, y1: ").split())
x2, y2 = map(int, input("Enter x2, y2: ").split())
bresenham_line(x1, y1, x2, y2)

# import matplotlib.pyplot as plt

# x1=int(input("Enter x1: "))
# y1=int(input("Enter y1: "))
# x2=int(input("Enter x2: "))
# y2=int(input("Enter y2: "))

# dx = x2 - x1
# dy = y2 - y1

# p = 2 *dy - dx

# x_points = []
# y_points = []

# x=x1
# y=y1

# while x<=x2:
#     x_points.append(x)
#     y_points.append(y)
    
#     if p<0:
#         x=x+1
#         y=y
#         p = p + 2*dy
#     else:
#         x = x + 1
#         y = y + 1
#         p = p + 2*dy - 2*dx

# plt.plot(x_points, y_points, marker='o') 


        
    