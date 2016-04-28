#!/usr/bin/python
fact=[1,1,1,1,1,1,1,1,1,1,1,1,1]
for i in range(2,13):
    fact[i]=fact[i-1]*i
m={0:'a',1:'b',2:'c',3:'d',4:'e',5:'f',6:'g',7:'h',8:'i',9:'j',10:'k',11:'l',12:'m'}
for _ in xrange(input()):
    n=[0,1,2,3,4,5,6,7,8,9,10,11,12]
    ans=""
    rem=input()-1
    for i in xrange(1,13):
        j=rem/fact[13-i]
        rem%=fact[13-i]
        ans+=str(m[n[j]])
        n.pop(j)
        if(rem==0):break
    for i in n:
        ans+=str(m[i])
    print ans


