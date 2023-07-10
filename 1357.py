def R(n):
    return int(str(n)[::-1])
X,Y=map(int,input().split())
print(R(R(X)+R(Y)))
