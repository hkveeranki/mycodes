""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
s=raw_input()
n=input()
p=len(s)/n
i=0
fl=True
if(len(s)%n!=0 or n>len(s)):fl=False
else:
    while i<len(s):
        t=s[i:i+p]
        if(t!=t[::-1]):
            fl=False
            break
        i+=p
if(fl):print "YES"
else:print "NO"
