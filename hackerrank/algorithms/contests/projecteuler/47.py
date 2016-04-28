""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
isp=[]
firp=[]
nump=[]
for i in xrange(2000006):
    isp.append(0)
    firp.append(i)
    nump.append(0)
isp[1]=isp[0]=1
for i in xrange(2,20001):
    if(isp[i]==0):
        nump[i]=1;
        for j in xrange(2*i,2000006,i):
            if(isp[j]==0):
                isp[j]=1
                firp[j]=i
for i in xrange(2,2000006):
    if(isp[i]==1):
        nump[i]=nump[i/firp[i]]
        if(firp[i/firp[i]]!=firp[i]):
            nump[i]+=1
        #print i,nump[i],firp[i],firp[i/firp[i]]
n,k=map(int,raw_input().split())
for i in xrange(2,n+1):
    fl=0
    if(nump[i]==k):
        for j in xrange(1,k):
            if(nump[i+j]!=k):   
                fl=1
                break
        if(fl==0):
            print i

