""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
l,r=map(int,raw_input().split());a,t=1,l^r
while(t):t/=2;a*=2
print a-1
