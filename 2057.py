n = int(input())

t = 2432902008176640000
if n == 0:
    n = -1

for i in range(20, 0, -1):
    t //= i
    if n >= t:
        n -= t

if n:
    print("NO")
else:
    print("YES")
