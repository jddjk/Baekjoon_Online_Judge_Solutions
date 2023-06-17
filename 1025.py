import math

def is_square_number(n):
    root = int(math.sqrt(n))
    return root * root == n

N, M = map(int, input().split())
table = [list(map(int, list(input().strip()))) for _ in range(N)]

max_square_num = -1

for i in range(N):
    for j in range(M):
        for dx in range(-N, N):
            for dy in range(-M, M):
                if dx == 0 and dy == 0:
                    continue

                x, y = i, j
                num = 0

                while 0 <= x < N and 0 <= y < M:
                    num = num * 10 + table[x][y]
                    if is_square_number(num):
                        max_square_num = max(max_square_num, num)

                    x += dx
                    y += dy

print(max_square_num)
