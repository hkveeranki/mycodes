for i in range(input()):
 a,b = map(int,raw_input().split())
 while a|(a+1)<=b: a|=(a+1)
 print a
