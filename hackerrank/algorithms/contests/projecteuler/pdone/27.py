""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
from math import *
isp=[]
ansa,ansb,ans=0,0,-1
for i in xrange(1000001):isp.append(0)
isp[0]=isp[1]=1
for i in xrange(2,1001):
    if isp[i]==0:
        for j in xrange(2*i,1000001,i):
            isp[j]=1
pri=[]
for i in xrange(2,2001):
    if isp[i]==0:
        pri.append(i)
#print pri
n=input()
for i in xrange(-n,n+1):
    for j in pri:
        if(j>n):break
        for it in xrange(2):
            p=0
            s=1 if it==0 else -1
            ao= -1 if i%2==0 else 0
            while(True):
                x=abs(p*p+(i+ao)*p + s*j)
                #print i,j,x,p
                if (isp[x]==1):break
                p+=1
            if(p>ans):
                ans=p
                ansa=i
                ansb=j
print ansa,ansb
