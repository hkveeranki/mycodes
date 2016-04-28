#!/usr/bin/python
for _  in xrange(input()):
    n=input()
    l=list(str(2**n))
    sum1=0
    for i in xrange(len(l)):
        sum1+=int(l[i])
    print sum1
