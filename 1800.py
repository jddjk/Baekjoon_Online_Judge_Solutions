import heapq
from typing import List, Tuple

def solve(v: List[List[Tuple[int, int]]], n: int, k: int, piv: int) -> bool:
    cost = [n] * (n+1)
    pq = [(0, 1)]

    while pq:
        maxx, node = heapq.heappop(pq)
        if cost[node] <= maxx:  
            continue
        cost[node] = maxx

        for i in range(len(v[node])):
            if v[node][i][1] <= piv and cost[v[node][i][0]] > maxx:
                heapq.heappush(pq, (maxx, v[node][i][0]))
            elif v[node][i][1] > piv and cost[v[node][i][0]] > maxx + 1:
                heapq.heappush(pq, (maxx+1, v[node][i][0]))
    return cost[n] <= k


def main():
    n, p, k = map(int, input().split())
    v = [[] for _ in range(n+1)]
    costs = [0] * 1000001

    for _ in range(p):
        a, b, c = map(int, input().split())
        v[a].append((b, c))
        v[b].append((a, c))
        costs[c] = 1

    costs[0] = 1
    ans = -1
    l, r = 0, 1000001

    while l < r:
        mid = (l + r) // 2
        if solve(v, n, k, mid):
            ans = mid
            r = mid
        else:
            l = mid + 1

    print(ans)


if __name__ == "__main__":
    main()
