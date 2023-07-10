def get_ans(n):
    MAX_N = 1000001
    zec = [0] * MAX_N
    fibo = []

    fib1, fib2 = 1, 2
    while True:
        fibo.append(fib1)
        zec[fib1] = fib1
        zec[fib2] = fib2
        next1, next2 = fib2, fib1 + fib2
        fib1, fib2 = next1, next2
        if fib1 >= MAX_N or fib2 >= MAX_N:
            break

    last = 3
    for i in range(4, MAX_N):
        if zec[i] != 0:
            last = i
        else:
            zec[i] = zec[i - last]

    for i in range(len(fibo) - 1):
        if n == fibo[i] or n == fibo[i + 1]:
            return -1
        if fibo[i] < n < fibo[i + 1]:
            return zec[n % fibo[i]]
    return zec[n % fibo[-1]]


N = int(input())
print(get_ans(N))
