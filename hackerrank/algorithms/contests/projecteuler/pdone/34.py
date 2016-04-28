""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
fact=[1,1,2,6,1,1,1,1,1,1]
for i in xrange(3,10):
    fact[i]=fact[i-1]*i
ans=0
for i in xrange(10,input()):
    temp=i
    sum1=0
    while(i!=0):
        sum1+=fact[i%10]
        i/=10
    if(sum1%temp==0):ans+=temp
print ans
