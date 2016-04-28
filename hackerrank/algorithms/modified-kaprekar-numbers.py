""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
p=input()
q=input()
lis=[]
for i in xrange(p,q+1):
    s=str(i*i)
    l=str(s[:len(s)/2])
    if(l!=""):l=int(l)
    else :l=0
    r=str(s[len(s)/2:])
    if(r!=""):r=int(r)
    else :r=0
    if l+r==i:
        lis.append(str(i))
if len(lis)==0 :print "INVALID RANGE"
else:print ' '.join(lis)
