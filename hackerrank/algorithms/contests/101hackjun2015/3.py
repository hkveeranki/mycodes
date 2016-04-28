""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
for _ in xrange(input()):
    a,b=raw_input().split()
    if int(a)<int(b):a,b=b,a
    ans=['0']*len(a)
    j=len(a)-1
    for i in xrange(len(b)-1,-1,-1):
        ans[j]=str(min(9,int(b[i])+int(a[j])))
        j-=1
    while j>=0:
        ans[j]=str(int(a[j]))
        j-=1
    if(int("9"*len(a))-int(a)<=int(b)):
        ans="9"*len(a)
        print ans
    else:print ''.join(ans)
