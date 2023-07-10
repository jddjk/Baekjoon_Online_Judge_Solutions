import sys

def push_function(a, b):
    if len(a) != len(b):
        return False
    if len(a) <= 1:
        return True

    al, ar, bl, br = [], [], [], []
    for i in range(1, len(a)):
        (al if a[i] < a[0] else ar).append(a[i])
        (bl if b[i] < b[0] else br).append(b[i])

    return push_function(al, bl) and push_function(ar, br)


for line in sys.stdin:
    prototypes, layers = map(int, line.split())
    tree = []
    result = 0
    for i in range(prototypes):
        tree.append(list(map(int, sys.stdin.readline().split())))

        j = 0
        while j < i:
            if push_function(tree[i], tree[j]):
                break
            j += 1

        if j == i:
            result += 1
    print(result)
