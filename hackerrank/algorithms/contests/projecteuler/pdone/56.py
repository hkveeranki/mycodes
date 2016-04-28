""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
ans=-1
for i in xrange(1,n+1):
    for j in xrange(1,n+1):
        p=str(i**j).strip('0')
        s=0
        for k in p:s+=int(k)
        ans=max(s,ans)
print ans
