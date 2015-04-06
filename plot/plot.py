#! /usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np
import pylab as pl

x1 = []
x2 = []
x3 = []
y1 = []
y2 = []
y3 = []

f = open("dot.txt")
i = 0
for line in f.readlines():
	s = line.split()
	if float(s[2]) > 0.55:
		x1.append(float(s[0]))
		y1.append(float(s[1]))
	elif float(s[2]) < 0.45:
		x2.append(float(s[0]))
		y2.append(float(s[1]))
	else:
		x3.append(float(s[0]))
		y3.append(float(s[1]))
	i = i + 1


pl.plot(x1, y1, 'or')
pl.plot(x2, y2, 'ob')
pl.plot(x3, y3, 'og')
pl.show()