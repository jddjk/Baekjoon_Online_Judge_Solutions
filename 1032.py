N = int(input())
file_names = [input() for _ in range(N)]

pattern = list(file_names[0])
for i in range(1, N):
    for j in range(len(file_names[i])):
        if pattern[j] != file_names[i][j]:
            pattern[j] = '?'

print(''.join(pattern))
