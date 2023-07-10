def calculate_pain_index(n, arr):
    arr.sort()
    MOD = 1_000_000_007
    result = 0
    p, m = 0, 0
    two = [0] * n
    temp = 1

    for i in range(n):
        two[i] = temp - 1
        temp *= 2
        temp %= MOD

    for i in range(n - 1, 0, -1):
        p += two[i] * arr[i]
        m += two[i] * arr[n - 1 - i]
        p %= MOD
        m %= MOD

    result = (p % MOD + MOD - m % MOD) % MOD
    return result


n = int(input())
arr = list(map(int, input().split()))

result = calculate_pain_index(n, arr)
print(result)
