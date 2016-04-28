for _ in range(input()):
    s=raw_input()
    S="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if s[0]=='R' and s[1].isdigit() and 'C' in s:
        s=s[1:]
        b,a=s.split('C')
        A=""
        a=int(a)
        while(a!=0):
            A+=S[a%26-1]
            if a%26==0:a-=1
            a/=26
        A=A[::-1]
        A+=b
    else:
        a=i=0
        while s[i].isalpha():i+=1
        for j in range(i): a=a*26+S.find(s[j])+1
        A="R"+s[i:]+"C"+str(a)
    print A
