def find_max_guminsu(N):
    while N>=4:
        if set(str(N)) <= {'4','7'}:
            return N
        N-=1
    return -1
print(find_max_guminsu(int(input())))
