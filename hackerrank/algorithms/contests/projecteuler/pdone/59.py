""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
dic={'a':97,'b':98,'c':99,'d':100,'e':101,'f':102,'g':103,'h':104,'i':105,'j':106,'k':107,'l':108,'m':109,'n':110,'o':111,'p':112,'q':113,'r':114,'s':115,'t':116,'u':117,'v':118,'w':119,'x':120,'y':121,'z':122,'A':65,'B':66,'C':67,'D':68,'E':69,'F':70,'G':71,'H':72,'I':73,'J':74,'K':75,'L':76,'M':77,'N':78,'O':79,'P':80,'Q':81,'R':82,'S':83,'T':84,'U':85,'V':86,'W':87,'X':88,'Y':89,'Z':90,'0':48,'1':49,'2':50,'3':51,'4':52,'5':53,'6':54,'7':55,'8':56,'9':57,';':59,':':58,',':44,'.':46,'\'':39,'?':63,'-':45,'!':33,' ':32,'(':40,')':41}
lis=[]
s="abcdefghijklmnopqrstuvwxyz"
main="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789;:,.'()?-! "
for i in s:
    temp=[]
    for j in main:
        val=dic[i]^dic[j]
        #print val
        temp.append(val)
    lis.append(temp)
n=input()
vals=map(int,raw_input().split())
ans=[[],[],[]]
ans1=""
for i in xrange(len(vals)):
    ans[i%3].append(vals[i])
for i in xrange(3):
    for j in xrange(len(lis)):
        fl=1
        for k in xrange(len(ans[i])):
            if not ans[i][k] in lis[j]:
                fl=0
                #print "for",i,s[j],"Broke for ",ans[i][k]
                break
        if fl==1:
            ans1+=s[j]
            break
print ans1
