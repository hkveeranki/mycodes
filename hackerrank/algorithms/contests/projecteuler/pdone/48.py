""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
mod=10**10
ans=long(0)
for i in xrange(1,n+1):
    ans=(ans+pow(i,i,mod))%mod
print ans
