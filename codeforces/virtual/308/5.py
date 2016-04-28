""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
inp=raw_input()
ans=0
a=[]
n=len(inp)
for i in xrange(n):
    if inp[i]=='*':
        a.append(i)
n=len(a)
for i in xrange(n):
    for j in xrange(i):
        tmp=inp[:a[i]] + ')' + inp[a[i]:]
        tmp=tmp[:a[j]+1] + '(' + tmp[a[j]+1:]
        ans=max(ans,eval(tmp))
    tmp=inp[:a[i]]+')'+inp[a[i]:]
    tmp='('+tmp
    ans=max(ans,eval(tmp))
    for j in xrange(i+1,n):
        tmp=inp[:a[i]+1] + '(' + inp[a[i]+1:]
        tmp=tmp[:a[j]+1] + ')' + tmp[a[j]+1:] 
        ans=max(ans,eval(tmp))  
    tmp=inp[:a[i]+1]+'('+inp[a[i]+1:]
    tmp=tmp+')'
    ans=max(ans,eval(tmp))
ans=max(ans,eval(inp))
print ans
