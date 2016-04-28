""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
for _ in xrange(input()):
    n=long(input())
    x=(-1+sqrt(1+8*n))/2.0
    if(ceil(x)==floor(x)):print "Go On Bob",long(ceil(x))
    else:print "Better Luck Next Time"
