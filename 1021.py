n, m = input().split()
n = int(n)
m = int(m)

positions = input().split()
positions = [int(x) for x in positions]

queue = list(range(1, n + 1))
count = 0

for pos in positions:
    queue_len = len(queue)
    queue_index = queue.index(pos)

    if queue_index < queue_len - queue_index:
        while True:
            if queue[0] == pos:
                del queue[0]
                break
            else:
                queue.append(queue[0])
                del queue[0]
                count += 1
    else:
        while True:
            if queue[0] == pos:
                del queue[0]
                break
            else:
                queue.insert(0, queue[-1])
                del queue[-1]
                count += 1

print(count)
