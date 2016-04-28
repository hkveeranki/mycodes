from random import *
n=100000
q=100000
f=randint
print n,q
for i in xrange(n):
    print i+f(1,1000000)
for i in xrange(q):
    p=f(1,100000)
    if(p==0):p+=f(1,4)
    s=f(1,n)
    e=f(1,n)
    v=f(1,100000000)
    if(s>e):s,e=e,s
    if(p==4):print p,s,e
    else:print p,s,e,v
