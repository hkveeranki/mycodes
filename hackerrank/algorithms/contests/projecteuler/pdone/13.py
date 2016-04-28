""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
res=long(0)
for _  in  xrange(input()):
    p=long(input())
    res+=p
p=list(str(res))
res=0
for i in xrange(10):
    res+=int(p[i])*(10**(9-i))
print res
