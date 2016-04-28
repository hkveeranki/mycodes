""" 
    Author:harry7

"""

def form(s):
	temp=""
	for i in s:
		if i=="+":
			temp+="*"
		else:
			temp+="+"
	return temp

#from time import time
#START=time()	
ans=["++","+*"]
b=1
n=input()
for b in range(1,n):
	temp=[]
	for i in ans:
		temp+=[i+i,i+form(i)]
	ans=temp

if n==0:
    print "+"
else:
    for i in ans:
	    print i
#print time()-START
