""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
mod=1000000007
def ipow(a,n):
    res=1
    while(n!=0):
        if(n&01):res=(res*a)%mod
        n>>=1
        a=(a*a)%mod
    return res
n=input()
lis=map(int,raw_input().split())
ans=1
for i in xrange(n):
    val=(ipow(2,lis[i])+1)%mod
    ans=(ans*val)%mod
print (ans-1)%mod
