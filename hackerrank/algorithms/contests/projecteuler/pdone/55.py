""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
def isp(n):
    s=str(n)
    if(s==s[::-1]):return True
    return False
n=input()
m={}
max1=-1
ans=""
for i in  xrange(1,n+1):
    s=str(i)
    if(isp(s)):
        m.setdefault(s,0)
        m[s]+=1
        if(m[s]>max1):
            max1=m[s]
            ans=s
        continue
    n=i
    for j in xrange(60):
        p=str(n)[::-1]
        s=str(int(p)+n)
        if(isp(s)):
            m.setdefault(s,0)
            m[s]+=1
            if(m[s]>max1):
                max1=m[s]
                ans=s
            break
        n=int(s)
print ans,max1
