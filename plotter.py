#!/usr/bin/python3

with open('cppResults.csv', 'r') as infile:
    cpp = [(0,float(i)) for i in infile.split(',')]
with open('scalaResults.csv', 'r') as infile:
    scala = [(1,float(i)) for i in infile.split(',')]

# Plot the Results or something
