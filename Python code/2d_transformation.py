import numpy as np
import matplotlib.pyplot as plt

print("--- Enter the original coordinates of the triangle ---")
x1 = float(input("Point 1 x: "))
y1 = float(input("Point 1 y: "))
x2 = float(input("Point 2 x: "))
y2 = float(input("Point 2 y: "))
x3 = float(input("Point 3 x: "))
y3 = float(input("Point 3 y: "))

print("\n--- Enter transformation values ---")
tx = float(input("Translation (x-axis): "))
ty = float(input("Translation (y-axis): "))
angle = float(input("Rotation Angle (degrees): "))
sx = float(input("Scaling (x-axis): "))
sy = float(input("Scaling (y-axis): "))

points = np.array([
    [x1, x2, x3, x1],
    [y1, y2, y3, y1],
    [1,  1,  1,  1]
])

T = np.array([[1, 0, tx], [0, 1, ty], [0, 0, 1]])

theta = np.radians(angle)
c, s = np.cos(theta), np.sin(theta)
R = np.array([[c, -s, 0], [s, c, 0], [0, 0, 1]])

S = np.array([[sx, 0, 0], [0, sy, 0], [0, 0, 1]])

transform = T @ R @ S
new_points = transform @ points

plt.figure(figsize=(6, 6))
plt.plot(points[0], points[1], 'b-o', label='Original')
plt.plot(new_points[0], new_points[1], 'r-o', label='Transformed')

plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.grid(True, linestyle='--')
plt.legend()
plt.show()