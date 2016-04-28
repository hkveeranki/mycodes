""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
isp=[]
for i in xrange(1000001):isp.append(0)
isp[0]=isp[1]=1
for i in xrange(2,1001):
    if(isp[i]==0):
        for j in xrange(2*i,1000001,i):
            isp[j]=1
pri=[]
for i in xrange(1000001):
    if(isp[i]==0):
        pri.append(i)
for _ in xrange(input()):
    ans=1
    n=input()
    for j in pri:
        if(ans*j>n):break
        else :ans*=j
    print ans
