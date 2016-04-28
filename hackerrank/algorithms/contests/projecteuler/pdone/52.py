""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n,k=map(int,raw_input().split())
for i in xrange(1,n+1):
    m=sorted(str(i))
    m=''.join(m)
    fl=1
    #print m
    for j in xrange(2,k+1):
        n=(str(i*j))
        if(n[0]=='0'):
            fl=0
            break
        n=sorted(n)
        n=''.join(n)
        #print m,n
        if(m!=n):
            fl=0
            break
    if fl==1:
        lis=[]
        for j in xrange(1,k+1):lis.append(str(i*j))
        print ' '.join(lis)
