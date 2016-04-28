def F(s):
    if len(s)%2==1:return s
    s1 = F(s[:len(s)//2])
    s2 = F(s[len(s)//2:])
    if s1 < s2:return s1 + s2
    return s2 + s1
if F(input()) == F(input()):
    print("YES")
else:
    print("NO")
