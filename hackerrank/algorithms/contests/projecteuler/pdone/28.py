""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
def f(n):
    if(n==1):return 1
    n-=1
    n/=2
    ans= long((8*n*(n+1)*(2*n+1))/3)
    ans+=n*4
    ans+=2*n*(n+1)
    ans+=1
    ans%=1000000007
    return ans
for __ in xrange(input()):
    n=long(input())
    print f(n)

