#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab

with open('cpp.csv', 'r') as infile:
    cpp = [float(i) for i in infile.read().split(',')]
with open('scala.csv', 'r') as infile:
    scala = [float(i) for i in infile.read().split(',')]


# the histogram of the data
cn, cbins, cpatches = plt.hist(cpp, 5, normed=1, facecolor='green', alpha=0.75)
sn, sbins, spatches = plt.hist(scala, 5, normed=1, facecolor='red', alpha=0.75)

# add a 'best fit' line
plt.xlabel('Time (Green = C++, Red = Scala)')
plt.ylabel('Frequency')
plt.title(r'Comparison of Scala and C++')
plt.grid(True)

plt.show()
