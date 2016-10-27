#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab

with open('cpp.csv', 'r') as infile:
    cpp = [float(i) for i in infile.read().split(',')]
with open('scala.csv', 'r') as infile:
    scala = [float(i) for i in infile.read().split(',')]


# the histogram of the data
n, bins, patches = plt.hist(cpp, 50, normed=1, facecolor='green', alpha=0.75)
n, bins, patches = plt.hist(scala, 50, normed=1, facecolor='red', alpha=0.75)

# add a 'best fit' line
plt.xlabel('Time')
plt.ylabel('Frequency')
plt.title(r'Comparison of scala and CPP')
#plt.axis([40, 160, 0, 0.03])
plt.grid(True)

plt.show()
