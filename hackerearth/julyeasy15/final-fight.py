""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
MOD=10**9+9
def fact(n):
    f=1
    for i in xrange(1,n+1):f*=i;f%=MOD;
    return f%MOD
N=input()
A=fact(N*2)
B=pow(fact(N), MOD-2, MOD)
ans=A*B*B*pow(N+1, MOD-2, MOD)%MOD
print ans
