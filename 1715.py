import heapq

N = int(input())
queue = []
for _ in range(N):
    heapq.heappush(queue, int(input()))

compare_count = 0
while len(queue) > 1:
    a = heapq.heappop(queue)
    b = heapq.heappop(queue)
    compare_count += a + b
    heapq.heappush(queue, a + b)

print(compare_count)
