""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
for _ in xrange(input()):
    n=input()
    if(n%2==0):
        if((n//2)&01):print 4
        else:print 3
    else:print 2
