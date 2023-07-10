import sys
sys.setrecursionlimit(10**6)
from sys import stdin
from typing import List, Tuple

def solve(M: int, N: int, Q: int, nodes: List[Tuple[str, int, int, int]], queries: List[Tuple[int, int]]):
    node_info = [None]
    max_id = 0
    for node in nodes:
        ch, x, y, z = node
        x, y, z = map(int, [x, y, z])
        max_id = max([max_id, x, y, z])
        if ch == 'S':
            node_info.append([x, 0, y, z])
        else:
            node_info.append([x, y, z, 0])
    
    input_node = [0] * (max_id+1)
    output_node = [0] * (max_id+1)
    for i in range(1, N+1):
        input_node[node_info[i][0]], input_node[node_info[i][1]], output_node[node_info[i][2]], output_node[node_info[i][3]] = i, i, i, i

    output_size = [-1] * (max_id+1)
    output_size[0] = 0

    def update_output_sizes(node_id: int, size: int):
        output_size[node_id] = size
        if input_node[node_id] == 0:
            return
        v = node_info[input_node[node_id]]
        if output_size[v[0]] == -1 or output_size[v[1]] == -1:
            return
        if v[1]:
            update_output_sizes(v[2], output_size[v[0]]+output_size[v[1]])
        else:
            update_output_sizes(v[2], (output_size[v[0]]+1)//2)
            update_output_sizes(v[3], (output_size[v[0]])//2)

    update_output_sizes(1, M)
    for i in range(2, max_id+1):
        if not output_node[i]:
            update_output_sizes(i, 0)

    for query in queries:
        x, k = query
        if k > output_size[x]:
            print("none")
            continue
        while x != 1:
            v = node_info[output_node[x]]
            if v[1]:
                sz = min(output_size[v[0]], output_size[v[1]])
                if k <= 2*sz:
                    x = v[not bool(k%2)]
                    k = (k+1)//2
                else:
                    x = v[output_size[v[1]] > output_size[v[0]]]
                    k -= sz
            else:
                k = 2*k - (v[2] == x)
                x = v[0]
        print(k)


if __name__ == "__main__":
    M, N, Q = map(int, stdin.readline().split())
    nodes = [tuple(stdin.readline().split()) for _ in range(N)]
    queries = [tuple(map(int, stdin.readline().split())) for _ in range(Q)]
    solve(M, N, Q, nodes, queries)
