""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
isp=[]
for i in xrange(1000001):isp.append(0)
isp[0]=isp[1]=1
for i in xrange(2,1001):
    if isp[i]==0:
        for j in xrange(2*i,1000001,i):
            isp[j]=1
pri=[]
for i in xrange(1001):
    if isp[i]==0:
        pri.append(i)
ways=[]
for j in xrange(1001):ways.append(0)
ways[0]=1
for i in pri:
    for j in xrange(i,1001):
        ways[j]+=ways[j-i];
for _ in xrange(input()):
    n=input()
    print ways[n]
