""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
for _  in xrange(input()):
    n=long(input())
    ans=(sqrt(1+8*n)-1)/2.0
    if(ceil(ans)==floor(ans)):ans=long(ans)
    else :ans=-1
    print ans
