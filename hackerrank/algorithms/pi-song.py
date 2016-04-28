""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
p="31415926535897932384626433833"
for _ in xrange(input()):
    lis=raw_input().split()
    s=""
    for j in lis:
        s+=str(len(j))
    pf=p[:len(s)]
    if(pf==s): print "It's a pi song."
    else: print "It's not a pi song."
