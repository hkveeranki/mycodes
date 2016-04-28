""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
inp=map(int,raw_input().split())
cnt=[]
for i in xrange(10001):cnt.append(0)
for i in inp:
    cnt[i]+=1
while(i<1001):
    if(cnt[i]>0):
        ans+=1
        i+=4
    i+=1
print ans
