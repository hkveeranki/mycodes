n = input()
probs = map(float, raw_input().split())
a = 1
tmp = 0
ans = 0
probs.sort()
probs = probs[::-1]
for pi in probs:
   tmp = tmp * (1-pi) + a * pi
   a *= (1-pi)
   ans = max(ans, tmp)
print ans
