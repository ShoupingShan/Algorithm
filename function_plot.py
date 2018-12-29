# -*- coding: utf-8 -*-
from matplotlib import pyplot as plt
import numpy as np
import math
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure()
ax = Axes3D(fig)
X = np.arange(-5, 15, 0.25)
Y = np.arange(3, 7, 0.25)
X, Y = np.meshgrid(X, Y)
R = 21.5+X*np.sin(4*math.pi*X)+Y*np.sin(20*math.pi*Y)
Z = np.sin(R)
ax.set_zlabel('f(X1,X2)')  # 坐标轴
ax.set_ylabel('X2')
ax.set_xlabel('X1')
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')

plt.show()