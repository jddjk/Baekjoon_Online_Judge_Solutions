N, K = map(int, input().split())
sequence = list(map(int, input().split()))

plugs = []
cnt = 0

for i in range(K):
    if sequence[i] in plugs:
        continue
    if len(plugs) < N:
        plugs.append(sequence[i])
    else:
        max_idx = 0
        for j in range(N):
            if plugs[j] not in sequence[i+1:]:
                max_idx = j
                break
            elif sequence[i+1:].index(plugs[j]) > sequence[i+1:].index(plugs[max_idx]):
                max_idx = j
        del plugs[max_idx]
        plugs.append(sequence[i])
        cnt += 1
print(cnt)
