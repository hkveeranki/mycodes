""" 
    Author:harry7

"""
import time
start=time.time()
n=input()
N=3
D=2
for i in xrange(n-1):
    N+=2*D
    D=N-D
    if len(str(D))<len(str(N)):print i+2
print time.time()-start
