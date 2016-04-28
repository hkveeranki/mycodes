""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
mod=1000000007
for _ in xrange(input()):
    n=input()
    a=map(int,raw_input().split())
    ans=0
    p=pow(2,n-1,mod)
    for i in xrange(n):
        ans|=a[i]
        ans%=mod
    ans=(ans*p)%mod
    print ans
