""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
n,k=map(long,raw_input().split())
l=long(factorial(n))
ans=ansi=0
for i in xrange(2,n+1):
    ansi=long(0)
    for j in xrange(i+1):
        val=long(factorial(i)/(factorial(j)*factorial(i-j)))
        if(val>k):
            ansi=j
            break
    if(ansi!=0):
        #print j
        ans+=i+1-(2*(ansi))
print ans
