#!/usr/bin/python
import random
ran=random.randint
n=ran(1,1000)%1001
print n
for i in xrange(n):
    print 
    print ran(1,16),ran(1,16)
