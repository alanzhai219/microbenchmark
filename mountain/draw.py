import sys
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(1, 65)  # stride
y = np.arange(1, 16)  # size ticks
x, y = np.meshgrid(x, y)

xticks = list((map(lambda stride: "s" + str(stride), range(1, 65))))
yticks = "32m 16m 8m 4m 2m 1024k 512k 256k 128k 64k 32k 16k 8k 4k 2k".split()

z0 = sys.argv[1]
z1 = z0.splitlines()[3:]
# Divide by tab, discard first and last column
z2 = np.array(list(map(lambda line: line.split("\t")[1:-1], z1)))
z2 = z2.astype(np.float).astype(np.int)

# define a figure
fig = plt.figure()
# convert to 3d
ax = plt.axes(projection="3d")

ax.set_xticks(range(1, 65, 4))
ax.set_yticks(range(1, 16, 2))
# Take only every other label
plt.rcParams.update({"font.size": 16})
ax.set_xticklabels(xticks[::4])
ax.set_yticklabels(yticks[::2])
ax.tick_params(axis="z", pad=10)
ax.set_xlabel("Stride", fontsize=18, labelpad=20)
ax.set_ylabel("Size", fontsize=18, labelpad=20)
ax.set_title("Memory Mountain\n", fontsize=22)
ax.plot_surface(x, y, z2, cmap="jet")
plt.tight_layout()
plt.show()