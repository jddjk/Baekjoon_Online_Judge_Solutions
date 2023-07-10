import sys

N = int(sys.stdin.readline())
plugs = [int(sys.stdin.readline()) for _ in range(N)]

total_plugs = sum(plugs) - (N - 1)

print(total_plugs)
