N, M = map(int, input().split())
J = int(input())

apples = [int(input()) for _ in range(J)]

now = 1
answer = 0

for apple in apples:
    if apple < now:
        answer += now - apple
        now = apple
    elif apple > now + M - 1:
        answer += apple - (now + M - 1)
        now = apple - (M - 1)
    else:
        pass

print(answer)
