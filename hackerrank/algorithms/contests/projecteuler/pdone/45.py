""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
def isp1(x):
    sol=(1+sqrt(1+24*x))/6.0
    if(ceil(sol)==floor(sol)):
        #print "x is",x,"sol is",sol
        return True
    return False
def isp2(x):
    sol=(-1+sqrt(1+8*x))/2.0
    if(ceil(sol)==floor(sol)):
        #print "x is",x,"sol is",sol
        return True
    return False
n,a,b=map(int,raw_input().split())
ans=[]
if(b==5):
    for i in xrange(1,n):
        val1=(i*(3*i-1))/2
        if(val1>=n):break
        if(isp2(val1)):print val1
else:
    for i in xrange(1,n):
        val1=i*(2*i-1)
        if(val1>=n):break
        if(isp1(val1)):print val1
