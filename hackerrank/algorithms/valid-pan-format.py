""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
for _ in xrange(input()):
    s=raw_input()
    a=[]
    b=[]
    for i in xrange(10):
        j=s[i]
        if(j.isdigit()):b.append(str(i))
        elif ord(j)>64 and ord(j)<91:a.append(str(i))
    a=''.join(sorted(a))
    b=''.join(sorted(b))
    if(a=="012349" and b=="5678"):print "YES"
    else:print "NO"
