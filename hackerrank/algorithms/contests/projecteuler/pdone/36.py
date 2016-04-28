""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
def con(x,k):
    lis=[]
    while(x!=0):
        lis.append(x%k)
        x/=k
    if(lis==lis[::-1]):return True
    return False
n,k=map(int,raw_input().split())
ans=0
for i in xrange(1,n):
    s=list(str(i))
    if(s==s[::-1] and con(i,k)==True):ans+=i
print ans
