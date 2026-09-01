import math
import matplotlib.pyplot as plt

print("Enter 8 vertices for the 3D Cuboid (x y z):")
x_orig, y_orig, z_orig = [], [], []
for i in range(8):
    x, y, z = map(float, input(f"Vertex {i+1}: ").split())
    x_orig.append(x)
    y_orig.append(y)
    z_orig.append(z)

print("\n--- 3D Transformation Menu ---")
print("1. Translation")
print("2. Rotation (Z-axis)")
print("3. Scaling")
print("4. Reflection (XY Plane)")
print("5. Shearing (X-axis relative to Z)")
choice = int(input("Choice: "))

if choice == 1:
    tx = float(input("Enter tx: "))
    ty = float(input("Enter ty: "))
    tz = float(input("Enter tz: "))
    x_trans = [x + tx for x in x_orig]
    y_trans = [y + ty for y in y_orig]
    z_trans = [z + tz for z in z_orig]
elif choice == 2:
    angle = float(input("Enter angle (in degrees): "))
    rad = math.radians(angle)
    x_trans = [x * math.cos(rad) - y * math.sin(rad) for x, y in zip(x_orig, y_orig)]
    y_trans = [x * math.sin(rad) + y * math.cos(rad) for x, y in zip(x_orig, y_orig)]
    z_trans = list(z_orig)
elif choice == 3:
    sx = float(input("Enter sx: "))
    sy = float(input("Enter sy: "))
    sz = float(input("Enter sz: "))
    x_trans = [x * sx for x in x_orig]
    y_trans = [y * sy for y in y_orig]
    z_trans = [z * sz for z in z_orig]
elif choice == 4:
    x_trans = list(x_orig)
    y_trans = list(y_orig)
    z_trans = [-z for z in z_orig]
elif choice == 5:
    shx = float(input("Enter shx: "))
    x_trans = [x + shx * z for x, z in zip(x_orig, z_orig)]
    y_trans = list(y_orig)
    z_trans = list(z_orig)

edges = [
    (0, 1), (1, 2), (2, 3), (3, 0),
    (4, 5), (5, 6), (6, 7), (7, 4),
    (0, 4), (1, 5), (2, 6), (3, 7)
]

fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

for edge in edges:
    ax.plot(
        [x_orig[edge[0]], x_orig[edge[1]]],
        [y_orig[edge[0]], y_orig[edge[1]]],
        [z_orig[edge[0]], z_orig[edge[1]]],
        "b--",
    )

for edge in edges:
    ax.plot(
        [x_trans[edge[0]], x_trans[edge[1]]],
        [y_trans[edge[0]], y_trans[edge[1]]],
        [z_trans[edge[0]], z_trans[edge[1]]],
        "r-",
    )

ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
plt.show()
