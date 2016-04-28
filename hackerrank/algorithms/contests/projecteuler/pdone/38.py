""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n,k=map(int,raw_input().split())
for i in xrange(2,n):
    str1=""
    p=[0,0,0,0,0,0,0,0,0,0,0,0]
    for j in xrange(1,10):
        fl=0
        str1=str(i*j)
        for l in str1:p[int(l)]+=1
        #print i,j,str1,p
        for l in xrange(1,k+1):
            if(p[l]!=1):
                fl=1
             #   print "For",i,j,"Broke for",l
                break
        #print "For",i,j,"fl is",fl
        if fl==0:
            break
    if(k==8 and p[9]!=0):fl=1
    if(p[0]!=0):fl=1
    if(fl==0):print i
