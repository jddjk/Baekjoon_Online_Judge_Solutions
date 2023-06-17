N, L = map(int, input().split())
for length in range(L, 101):
    a = (2 * N - length ** 2 + length) / (2 * length)
    if a - int(a) < 1e-9 and a >= 0:
        answer = [int(a + i) for i in range(length)]
        print(' '.join(map(str, answer)))
        break
else:
    print(-1)
