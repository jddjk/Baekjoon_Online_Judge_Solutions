import sys
from collections import deque

def bfs(start, graph, colors):
    colors[start] = 1
    queue = deque([start])
    
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if colors[i] == 0:
                colors[i] = -1 * colors[v]
                queue.append(i)
            elif colors[i] == colors[v]:
                return False
    return True

def is_bipartite(graph, V):
    colors = [0] * (V+1)
    
    for i in range(1, V+1):
        if colors[i] == 0:
            if not bfs(i, graph, colors):
                return "NO"
    return "YES"

K = int(sys.stdin.readline())
for _ in range(K):
    V, E = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(V+1)]
    
    for _ in range(E):
        u, v = map(int, sys.stdin.readline().split())
        graph[u].append(v)
        graph[v].append(u)

    print(is_bipartite(graph, V))
