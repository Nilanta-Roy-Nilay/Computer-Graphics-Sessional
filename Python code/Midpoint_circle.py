import matplotlib.pyplot as plt

xc, yc, r = map(int, input("Enter xc yc r: ").split())

x = 0
y = r
p = 1 - r
xs = []
ys = []

while x <= y:
    pts = [
        (xc + x, yc + y), (xc + y, yc + x),
        (xc + x, yc - y), (xc + y, yc - x),
        (xc - x, yc - y), (xc - y, yc - x),
        (xc - x, yc + y), (xc - y, yc + x)
    ]
    for px, py in pts:
        xs.append(px); ys.append(py)

    x += 1
    if p < 0:
        p += 2 * x + 1
    else:
        y -= 1
        p += 2 * (x - y) + 1

plt.scatter(xs, ys, s=10, color='red')
plt.gca().set_aspect('equal', adjustable='box')
plt.axhline(0, color='black'); plt.axvline(0, color='black')
plt.show()
