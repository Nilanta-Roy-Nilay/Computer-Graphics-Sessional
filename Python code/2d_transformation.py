import math
import matplotlib.pyplot as plt

points = [(100, 100), (200, 100), (200, 200), (100, 200)]
x_orig = [p[0] for p in points] + [points[0][0]]
y_orig = [p[1] for p in points] + [points[0][1]]

print(
    "1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5."
    " Shearing\nChoice:"
)
choice = int(input())

fig, ax = plt.subplots()
ax.plot(x_orig, y_orig, "b--", label="Original")

if choice == 1:  # Translation
    tx, ty = 80, 50
    ax.plot(
        [x + tx for x in x_orig],
        [y + ty for y in y_orig],
        "r-",
        label="Translated",
    )
elif choice == 2:  # Rotation
    rad = math.radians(45)
    rx = [x * math.cos(rad) - y * math.sin(rad) for x, y in zip(x_orig, y_orig)]
    ry = [x * math.sin(rad) + y * math.cos(rad) for x, y in zip(x_orig, y_orig)]
    ax.plot(rx, ry, "r-", label="Rotated")
elif choice == 3:  # Scaling
    sx, sy = 1.5, 1.5
    ax.plot(
        [x * sx for x in x_orig], [y * sy for y in y_orig], "r-", label="Scaled"
    )
elif choice == 4:  # Reflection (X-axis)
    ax.plot(x_orig, [-y for y in y_orig], "r-", label="Reflected")
    ax.axhline(0, color="black", linewidth=1)
elif choice == 5:  # Shearing (X-axis)
    shx = 1.0
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
