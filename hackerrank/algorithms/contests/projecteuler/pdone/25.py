""" Author: Hemanth Kumar Veeranki
    Handle:harry7
"""
#!/usr/bin/python
from math import *
for _ in xrange(input()):
    n=input()
    n-=1
    ans=(n*(log(10))+(log(5)/2))/log(1.618033988749895)
    ans=ceil(ans)
    if(n==0):ans=1
    print  int(ans)

