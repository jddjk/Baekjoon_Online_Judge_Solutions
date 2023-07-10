import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    distance = [INF] * (n + 1)
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

T = int(input())
for _ in range(T):
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d))
        graph[b].append((a, d))
    x = []
    for _ in range(t):
        x.append(int(input()))

    start_ = dijkstra(s)
    g_ = dijkstra(g)
    h_ = dijkstra(h)
    
    result = []
    for i in x:
        if start_[g] + g_[h] + h_[i] == start_[i] or start_[h] + h_[g] + g_[i] == start_[i]:
            result.append(i)
    result.sort()
    for i in result:
        print(i, end=' ')
    print()
