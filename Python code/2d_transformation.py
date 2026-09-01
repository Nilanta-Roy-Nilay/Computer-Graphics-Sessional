import math
import matplotlib.pyplot as plt

print("Enter 4 points for the rectangle (x y):")
points = []
for i in range(4):
    x, y = map(float, input(f"Point {i+1}: ").split())
    points.append((x, y))

x_orig = [p[0] for p in points] + [points[0][0]]
y_orig = [p[1] for p in points] + [points[0][1]]

print("\n--- 2D Transformation Menu ---")
print("1. Translation")
print("2. Rotation")
print("3. Scaling")
print("4. Reflection (X-axis)")
print("5. Shearing (X-axis)")
choice = int(input("Choice: "))

fig, ax = plt.subplots()
ax.plot(x_orig, y_orig, "b--", label="Original")

if choice == 1:
    tx = float(input("Enter tx: "))
    ty = float(input("Enter ty: "))
    ax.plot(
        [x + tx for x in x_orig],
        [y + ty for y in y_orig],
        "r-",
        label="Translated",
    )
elif choice == 2:
    angle = float(input("Enter angle (in degrees): "))
    rad = math.radians(angle)
    rx = [x * math.cos(rad) - y * math.sin(rad) for x, y in zip(x_orig, y_orig)]
    ry = [x * math.sin(rad) + y * math.cos(rad) for x, y in zip(x_orig, y_orig)]
    ax.plot(rx, ry, "r-", label="Rotated")
elif choice == 3:
    sx = float(input("Enter sx: "))
    sy = float(input("Enter sy: "))
    ax.plot(
        [x * sx for x in x_orig], [y * sy for y in y_orig], "r-", label="Scaled"
    )
elif choice == 4:
    ax.plot(x_orig, [-y for y in y_orig], "r-", label="Reflected")
    ax.axhline(0, color="black", linewidth=1)
elif choice == 5:
    shx = float(input("Enter shx: "))
    ax.plot(
        [x + shx * y for x, y in zip(x_orig, y_orig)],
        y_orig,
        "r-",
        label="Sheared",
    )

ax.set_aspect("equal")
plt.grid(True)
plt.legend()
plt.show()
