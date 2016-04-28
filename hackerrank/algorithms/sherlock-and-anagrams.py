""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
for _ in xrange(input()):
    s=raw_input()
    n=len(s)
    cnt=0
    for l in xrange(1,n+1):
        for i in xrange(n-l+1):
            for j in xrange(i+1,n-l+1):
                if(i!=j):
                    if(sorted(s[i:i+l])==sorted(s[j:j+l])):cnt+=1
    print cnt
