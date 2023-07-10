import sys
import heapq
from math import dist

def prim(graph, start_node):
    mst = list()
    visited = [False] * len(graph)
    keys = [float('inf')] * len(graph)
    queue = []

    keys[start_node] = 0
    heapq.heappush(queue, (0, start_node))

    while queue:
        key, node = heapq.heappop(queue)
        if visited[node] == False:
            visited[node] = True
            mst.append((node, key))
            for linked_node, linked_key in graph[node]:
                if visited[linked_node] == False and keys[linked_node] > linked_key:
                    keys[linked_node] = linked_key
                    heapq.heappush(queue, (linked_key, linked_node))
    return mst

n = int(input())
stars = []
for _ in range(n):
    x, y = map(float, input().split())
    stars.append((x, y))

graph = [[] for _ in range(n)]
for i in range(n):
    for j in range(i+1, n):
        distance = dist(stars[i], stars[j])
        graph[i].append((j, distance))
        graph[j].append((i, distance))

mst = prim(graph, 0)
result = sum(key for node, key in mst)

print('%.2f' % result)
