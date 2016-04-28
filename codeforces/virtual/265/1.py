""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
s=raw_input()
p=0
k=1
for i in xrange(n):
    p=p+k*int(s[i])
    k*=2
p+=1
f=""
for i in xrange(n):
    f+=str(p%2)
    p/=2
cnt=0
for i in xrange(n):
    if(s[i]!=f[i]):cnt+=1
print cnt
