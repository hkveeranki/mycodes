""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
def gcd(a,b):
    if a==0:return b
    return gcd(b%a,a)
for _ in xrange(input()):
    x1,y1,x2,y2=map(int,raw_input().split())
    print gcd(abs(x1-x2),abs(y1-y2))-1
