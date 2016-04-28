""" 
    Author: Hemanth Kumar Veeranki
    Handle:harry7

"""
#!/usr/bin/python
n,m = map(int,raw_input().split())
if n >= m:
    print n-m
else:
    used = [False]*50001
    used[n] = True
    que = [[n,0]]
    while 1:
        k,i = que.pop(0)
        if k == m:
            break
        if k < m and not used[2*k]:
            used[2*k] = True
            que.append([2*k,i+1])
        if 1 < k and not used[k-1]:
            used[k-1] = True
            que.append([k-1,i+1])
    print i
