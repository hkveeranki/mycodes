def F(a,b):
    if a==0:return b
    return F(b%a,a)
def f(a,b):return a*b/F(a,b)
n=input()
if n < 3: print n
else:
    p=f(n,n-1)
    p=f(p,n-2)
    print p
