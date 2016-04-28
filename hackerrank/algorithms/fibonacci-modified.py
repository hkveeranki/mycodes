""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
f=[0]*25
a,b,n=map(int,raw_input().split())
f[1],f[2]=a,b
for i in xrange(3,n+2):
    f[i]=f[i-1]*f[i-1]+f[i-2]
print f[n]
