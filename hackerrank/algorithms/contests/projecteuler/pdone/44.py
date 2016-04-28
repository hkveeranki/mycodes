""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
def isp(x):
    sol=(1+sqrt(1+24*x))/6.0
    if(ceil(sol)==floor(sol)):
        #print "x is",x,"sol is",sol
        return True
    return False
n,k=map(int,raw_input().split())
for i in xrange(k+1,n):
    val1=(i*(3*i-1))/2
    x=i-k;
    val2=(x*(3*x-1))/2
    val3=val1-val2
    val4=val1+val2
    #print i,val1,val2,val3,val4
    if((val3>0 and isp(val3)) or (val4 >0 and isp(val4))):print val1
