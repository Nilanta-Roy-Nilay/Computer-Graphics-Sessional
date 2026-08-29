import matplotlib.pyplot as plt

x1=int(input("Enter the value of x1:"))
y1=int(input("Enter the value of y1:"))
x2=int(input("Enter the value of x2:"))
y2=int(input("Enter the value of y2:"))


dx=x2-x1
dy=y2-y1

m=dy/dx

x= x1
y=y1


x_point=[]
y_point=[]

while(round(x)!=x2):
    x_point.append(round(x))
    y_point.append(round(y))

if abs(dx)>=abs(dy):
    x=x+1
    y=y+m
   
else:
    x=x+(1/m)
    y=y+1
  
plt.plot(x_point,y_point)
plt.show()

