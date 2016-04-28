""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from decimal import *
def solve(s,p):
    ans1=0
    for i in xrange(p+1):
        if(s[i]!='.'):
            ans1+=int(s[i])
    return ans1
lis=[]
for i in xrange(1,32):lis.append(i*i)
n=input()
p=input()
getcontext().prec=p+10
ans=0
for i in xrange(1,n+1):
    if not i in lis:
        ans+=solve(str(Decimal(i).sqrt()),p)
print ans
