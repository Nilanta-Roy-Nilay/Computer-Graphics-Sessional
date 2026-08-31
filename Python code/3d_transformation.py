import math
import matplotlib.pyplot as plt

# 3D Box coordinates
x1, y1, x2, y2, z1, z2 = 1, 1, 2, 2, 1, 2

print(
    "1. Translation\n2. Rotation (Z-axis)\n3. Scaling\n4. Reflection\n5."
    " Shearing\nChoice:"
)
choice = int(input())

fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Simple base coordinates for visual box
x = [x1, x2, x2, x1, x1]
y = [y1, y1, y2, y2, y1]
z = [z1, z1, z1, z1, z1]

ax.plot(x, y, z, "b--", label="Original")

if choice == 1:  # Translation
    tx, ty, tz = 2, 2, 1
    ax.plot(
        [i + tx for i in x],
        [i + ty for i in y],
        [i + tz for i in z],
        "r-",
        label="Translated",
    )
elif choice == 2:  # Rotation (Z-axis)
    rad = math.radians(45)
    rx = [i * math.cos(rad) - j * math.sin(rad) for i, j in zip(x, y)]
    ry = [i * math.sin(rad) + j * math.cos(rad) for i, j in zip(x, y)]
    ax.plot(rx, ry, z, "r-", label="Rotated")
elif choice == 3:  # Scaling
    sx, sy, sz = 1.5, 1.5, 1.5
    ax.plot(
        [i * sx for i in x],
        [i * sy for i in y],
        [i * sz for i in z],
        "r-",
        label="Scaled",
    )
elif choice == 4:  # Reflection (XY plane)
    ax.plot(x, y, [-i for i in z], "r-", label="Reflected")
elif choice == 5:  # Shearing
    shx = 0.5
    ax.plot(
        [i + shx * j for i, j in zip(x, y)], y, z, "r-", label="Sheared"
    )

ax.legend()
plt.show()
