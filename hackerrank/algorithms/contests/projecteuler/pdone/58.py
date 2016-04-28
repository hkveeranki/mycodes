""" 
    Author:harry7

"""
from time import time
START=time()
def isp(n):
        if n <= 1: return False;
        if n == 2: return True;
        if n % 2 == 0: return False;
        if n < 9: return True;
        if n % 3 == 0: return False;            
        counter = 5;            
        while ((counter * counter) <= n):
                if (n % counter == 0) :return False;
                if (n % (counter + 2) == 0): return False;
                counter += 6;
        return True;
np=3
sl=2
c=9
n=input()
p=float(n)/100
while (float(np)/(2*sl+1))>=p:
    sl+=2
    for i in range(3):
        c+=sl
        if isp(c):np+=1
    c+=sl
print sl+1
print time()-START
