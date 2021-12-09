import numpy as numpy
import math

def fun(x,y):
	pi = 3.14159
	sigma = 1.4
	ex = x**2
	ey = y**2
	temp = - ((ex+ey)/(2*(sigma**2)))
	return ((-1/(pi*(sigma**4)))*(1 + temp)*math.exp(temp))

for x in range(-7,8):
	print('{') 
	for y in range(-7,8):
		print(round(math.floor(1000*round(fun(x,y),20)), 20), end=",")
		#print(round(fun(x,y),6), end=",")

	print('},')
	# print("-------------------------------------------------")
