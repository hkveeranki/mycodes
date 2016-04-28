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
for i in xrange(10,1000001):
    if isp[i]==0:
        pri.append(i)
n=input()
ans=0
an=[]
for idx in range(len(pri)):
    i=pri[idx]
    if(i>=n):break
    fl=0
    s=list(str(i))
    p=s[::-1]
    #print i,p,s
    while(len(s)!=1):
        s.pop()
        num=int(''.join(s))
        #print "s",s,"num",num
        if isp[num]==1:
            fl=1
            #print "Got 1 for",num,"isp ",isp[num]
            break
    while(len(p)!=1):
        p.pop()
        pp=p[::-1]
        num=int(''.join(pp))
        #print "p",p,"num",num
        if isp[num]==1:
            #print "Got 1 for",num,"isp ",isp[num]
            fl=1
            break
    #print i,fl
    if(fl==0):
        an.append(i)
        ans+=i
#print an
print ans
