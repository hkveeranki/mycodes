""" 
   Author: Hemanth Kumar Veeranki
   Handle:harry7

"""
#!/usr/bin/python
''' From O'Reilly's Python Cookbook '''

def _combinators(_handle, items, n):
    if n==0:
        yield []
        return
    for i, item in enumerate(items):
        this_one = [ item ]
        for cc in _combinators(_handle, _handle(items, i), n-1):
            yield this_one + cc

def combinations(items, n):
    ''' take n distinct items, order matters '''
    def skipIthItem(items, i):
        return items[:i] + items[i+1:]
    return _combinators(skipIthItem, items, n)

def uniqueCombinations(items, n):
    ''' take n distinct items, order is irrelevant '''
    def afterIthItem(items, i):
        return items[i+1:]
    return _combinators(afterIthItem, items, n)

def selections(items, n):
    ''' take n (not necessarily distinct) items, order matters '''
    def keepAllItems(items, i):
        return items
    return _combinators(keepAllItems, items, n)

def permutations(items):
    ''' take all items, order matters '''
    return combinations(items, len(items))
def val(n):
   s=0
   for i in n:s=s*10+i
   return s
m={}
n=input()
for perm in permutations(range(1,n+1)):
   for cross in xrange(1,n/2):
       for eq in xrange(cross+1,n/2+2):
           a=val(perm[0:cross])
           b=val(perm[cross:eq])
           c=val(perm[eq:n])
           #print a,b,c
           if(a*b==c):m[c]=1
print sum(i for i in m)


