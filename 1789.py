import math

def max_n(S):
    return (-1 + math.sqrt(1+8*S))//2

if __name__ == "__main__":
    S = int(input())
    print(int(max_n(S)))
