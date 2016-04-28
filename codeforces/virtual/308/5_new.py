s="1*"+input()+"*1"
L=len(s)
f=eval
p=f(s)
for j in range(L):
    if s[j] == '*':
        for i in range(j+1,L):
            if s[i] == '*':p=max(p,f(s[:j+1]+'('+s[j+1:i]+')'+s[i:]))
print(p)
