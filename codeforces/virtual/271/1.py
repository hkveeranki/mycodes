""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
s="""qwertyuiop
asdfghjkl;
zxcvbnm,./"""
t=raw_input()
m=raw_input()
ans=""
val=1
if(t=='R'):val=-1
for j in m:
    t=s.find(j)
    t=(t+val)%33
    ans+=s[t]
print ans
