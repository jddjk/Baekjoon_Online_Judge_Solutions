N = int(input())
factorial = 1
for i in range(1, N+1):
    factorial *= i
    while factorial % 10 == 0:
        factorial //= 10
    factorial %= 10**30
print(str(factorial)[-5:])
