""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
isp=[]
for i in xrange(0,1000001):isp.append(0)
isp[0]=isp[1]=1
for i in xrange(2,1001):
    if(isp[i]==0):
        for j in xrange(2*i,1000001,i):
            isp[j]=1
pri=[]
for i in xrange(1000001):
    if(isp[i]==0):
        pri.append(i)
n=input()
j=ans=0
while (True):
    fl=1
    if(j>=len(pri) or pri[j]>n):break
    lis=list(str(pri[j]))
    while(True):
        l=lis[-1]
        lis.pop()
        lis.insert(0,l)
        num=int(''.join(lis))
        if(num==pri[j]):break
        if(num>n or isp[num]==1):
            fl=0
            break
    if(fl==1):ans+=pri[j]
    j+=1
print ans

