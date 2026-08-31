import math
import matplotlib.pyplot as plt
from matplotlib.widgets import Dropdown
from matplotlib.patches import Polygon, Rectangle

# মূল শেপ (Square Baseline)
x1, y1 = 100, 100
width, height = 100, 100
points = [(100, 100), (200, 100), (200, 200), (100, 200)]

# Fig and Axis Setup
fig, ax = plt.subplots(figsize=(8, 7))
plt.subplots_adjust(top=0.85)

# Original Rectangle (Blue Dashed Line)
orig_patch = Rectangle((x1, y1), width, height, fill=False, edgecolor="blue", linestyle="--", label="Original")
ax.add_patch(orig_patch)

# Transformed Patch Holder
transformed_patch = None

def update_transformation(label):
    global transformed_patch
    
    # আগের রূপান্তর সরিয়ে ফেলা
    if transformed_patch in ax.patches:
        transformed_patch.remove()
        
    if label == "Translation":
        tx, ty = 100, 50
        transformed_patch = Rectangle((x1 + tx, y1 + ty), width, height, fill=False, edgecolor="red", linewidth=2, label="Translated")
        ax.set_xlim(0, 350)
        ax.set_ylim(0, 300)
        
    elif label == "Rotation":
        angle = 45
        rad = math.radians(angle)
        rotated = [(px * math.cos(rad) - py * math.sin(rad), px * math.sin(rad) + py * math.cos(rad)) for px, py in points]
        transformed_patch = Polygon(rotated, fill=False, edgecolor="red", linewidth=2, label="Rotated")
        ax.set_xlim(-150, 300)
        ax.set_ylim(-50, 300)
        
    elif label == "Scaling":
        sx, sy = 1.5, 2.0
        transformed_patch = Rectangle((x1 * sx, y1 * sy), width * sx, height * sy, fill=False, edgecolor="red", linewidth=2, label="Scaled")
        ax.set_xlim(0, 350)
        ax.set_ylim(0, 350)
        
    elif label == "Reflection":
        transformed_patch = Rectangle((x1, -y1 - height), width, height, fill=False, edgecolor="red", linewidth=2, label="Reflected")
        ax.set_xlim(0, 350)
        ax.set_ylim(-300, 300)
        
    elif label == "Shearing":
        shx = 1
        sheared = [(px + shx * py, py) for px, py in points]
        transformed_patch = Polygon(sheared, fill=False, edgecolor="red", linewidth=2, label="Sheared")
        ax.set_xlim(0, 500)
        ax.set_ylim(0, 300)

    ax.add_patch(transformed_patch)
    ax.set_aspect('equal')
    ax.grid(True, linestyle=":", alpha=0.6)
    ax.legend(loc="upper right")
    fig.canvas.draw_idle()

# Dropdown UI
dropdown_ax = plt.axes([0.3, 0.9, 0.4, 0.05])
transformation_dropdown = Dropdown(
    ax=dropdown_ax,
    label="Select Transformation: ",
    options=["Translation", "Rotation", "Scaling", "Reflection", "Shearing"],
    active=0
)

# Event Listener Binding
transformation_dropdown.on_select(update_transformation)

# Default View setup
update_transformation("Translation")

plt.show()
