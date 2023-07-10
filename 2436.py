import math
gcd,lcm=map(int,input().split())
tmp=lcm//gcd
resA,resB=0,0

for i in range(1,int(math.sqrt(tmp))+1):
    if tmp % i == 0:
        tmpA=i
        tmpB=tmp//i
        if math.gcd(tmpA, tmpB)==1:
            resA=tmpA*gcd
            resB=tmpB*gcd
print(resA,resB)
