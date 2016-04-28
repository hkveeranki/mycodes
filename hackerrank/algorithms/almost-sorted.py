""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
a=map(int,raw_input().split())
i=0
if(a==sorted(a)):
    print "yes"
else:
    while(i<n and a[i]<a[i+1]):i+=1
    s=i
    i=n-1
    while(i>0 and a[i]>a[i-1]):i-=1
    e=i
    a[s],a[e]=a[e],a[s]
    if(a==sorted(a)):
        print "yes"
        print "swap",s+1,e+1
    else:
        a[s],a[e]=a[e],a[s]
        state=1
        if(state==1):
                if s<1:
                    a=a[:s]+a[e::-1]+a[e+1:]
                else:
                    a=a[:s]+a[e:s-1:-1]+a[e+1:]
                if a==sorted(a):
                    print "yes"
                    print "reverse",s+1,e+1
                else:
                    print "no"

