""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
for _ in xrange(input()):
    lis=raw_input().split()
    if(lis[0]=="hackerrank" and lis[-1]=="hackerrank"):print "0"
    elif lis[0]=="hackerrank":print 1
    elif lis[-1]=="hackerrank":print 2
    else: print -1
