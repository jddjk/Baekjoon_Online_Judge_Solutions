import heapq
from sys import stdin

n, m = map(int, stdin.readline().split())
adj = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
heap = []
result = []

for _ in range(m):
    x, y = map(int, stdin.readline().split())
    adj[x].append(y)
    indegree[y] += 1

for i in range(1, n + 1):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

while heap:
    data = heapq.heappop(heap)
    result.append(data)
    for y in adj[data]:
        indegree[y] -= 1
        if indegree[y] == 0:
            heapq.heappush(heap, y)

for i in result:
    print(i, end=' ')
