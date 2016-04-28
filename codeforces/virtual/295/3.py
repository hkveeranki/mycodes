""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n=input()
s=raw_input()
c=[s.count(x) for x in 'ACTG']
print pow(c.count(max(c)),n,1000000007)
