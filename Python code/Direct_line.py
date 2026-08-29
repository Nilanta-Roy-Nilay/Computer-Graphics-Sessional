import matplotlib.pyplot as plt

x1=int(input("Enter the value of x1:"))
y1=int(input("Enter the value of y1:"))
x2=int(input("Enter the value of x2:"))
y2=int(input("Enter the value of y2:"))


dx=x2-x1
dy=y2-y1

m=dy/dx
if dx>0:
    x=x1
    y=y1
    xend = x2
else:
    x=x2
    y=y2
    xend= x1
c = y-m*x

x_point=[]
y_point=[]

while(x!=xend):
    x_point.append(round(x))
    y_point.append(round(y))

    x=x+1
    y=m*x+c
plt.plot(x_point,y_point)
plt.show()


