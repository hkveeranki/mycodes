""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from sets import Set
from math import *
def solve(d,p):
    set1=Set([])
    if(d<0):return 0
    x=(-d+sqrt(d+4*p))/2.0
    if(ceil(x)==floor(x)):set1.add(int(x))
    x=(-d-sqrt(d+4*p))/2.0
    if(ceil(x)==floor(x)):set1.add(int(x))
    x=(d+sqrt(d+4*p))/2.0
    if(ceil(x)==floor(x)):set1.add(int(x))
    x=(d-sqrt(d+4*p))/2.0
    if(ceil(x)==floor(x)):set1.add(int(x))
    return len(set1)   
for _ in xrange(input()):
    d,p=map(int,raw_input().split())
    print solve(d,p)
