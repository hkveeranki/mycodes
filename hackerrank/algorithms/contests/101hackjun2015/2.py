""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
from math import *
def gcd(a,b):
    if(a==0):return b
    return gcd(b%a,a)
for _ in  xrange(input()):
    a,b=map(int,raw_input().split())
    r=a
    if(a>b):a%=b
    p=b/4.0-a
    if(p<0):p+=b
    r+=p
    r=int(floor(r))
    p=gcd(r,b)
    if(r%b==0):print r,"0/1"
    else: 
        a=r%b
        print r,str(a/p)+"/"+str(b/p)
