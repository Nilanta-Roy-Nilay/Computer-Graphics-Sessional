import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

fig, ax = plt.subplots()

# Original
ax.add_patch(Rectangle((100, 100), 100, 100, fill=False))

# Translation
tx = 100
ty = 50

ax.add_patch(Rectangle((100 + tx, 100 + ty),
                       100, 100, fill=False))

ax.set_xlim(0, 350)
ax.set_ylim(0, 300)
ax.set_aspect('equal')
plt.show()






rotation

import matplotlib.pyplot as plt
from matplotlib.patches import Polygon
import math

points = [
    (100, 100),
    (200, 100),
    (200, 200),
    (100, 200)
]

angle = 45
rad = math.radians(angle)

rotated = []

for x, y in points:
    nx = x * math.cos(rad) - y * math.sin(rad)
    ny = x * math.sin(rad) + y * math.cos(rad)
    rotated.append((nx, ny))

fig, ax = plt.subplots()

ax.add_patch(
    Polygon(points, fill=False)
)

ax.add_patch(
    Polygon(rotated, fill=False)
)

ax.set_xlim(-150, 300)
ax.set_ylim(-50, 300)
ax.set_aspect('equal')
plt.show()




scaling

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

x1 = 100
y1 = 100
width = 100
height = 100

sx = 1.5
sy = 2.0

fig, ax = plt.subplots()

# Original
ax.add_patch(
    Rectangle((x1, y1), width, height, fill=False)
)

# Scaled
ax.add_patch(
    Rectangle((x1 * sx, y1 * sy),
              width * sx,
              height * sy,
              fill=False)
)

ax.set_xlim(0, 350)
ax.set_ylim(0, 350)
ax.set_aspect('equal')
plt.show()





reflection

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

x = 100
y = 100
w = 100
h = 100

fig, ax = plt.subplots()

# Original
ax.add_patch(
    Rectangle((x, y), w, h, fill=False)
)

# Reflection about X-axis
ax.add_patch(
    Rectangle((x, -y - h), w, h, fill=False)
)

ax.axhline(0)

ax.set_xlim(0, 350)
ax.set_ylim(-300, 300)
ax.set_aspect('equal')
plt.show()






Shearing

import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

points = [
    (100, 100),
    (200, 100),
    (200, 200),
    (100, 200)
]

shx = 1

sheared = []

for x, y in points:
    nx = x + shx * y
    ny = y
    sheared.append((nx, ny))

fig, ax = plt.subplots()

# Original
ax.add_patch(
    Polygon(points, fill=False)
)

# Sheared
ax.add_patch(
    Polygon(sheared, fill=False)
)

ax.set_xlim(0, 500)
ax.set_ylim(0, 300)
ax.set_aspect('equal')
plt.show()
