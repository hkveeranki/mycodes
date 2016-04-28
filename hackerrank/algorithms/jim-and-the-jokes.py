""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
dic={}
def fval(a,b):
    val,r=0,1
    a=a[::-1]
    for j in a:
        if(int(j)<b):val+=int(j)*r
        else:return False
        r*=b
    dic.setdefault(val,0)
    dic[val]+=1
for _ in xrange(input()):
    b,a=raw_input().split()
    b=int(b)
    fval(a,b)
ans=0
for i in dic:
    p=dic[i]
    ans+=(p*(p-1))/2
print ans
