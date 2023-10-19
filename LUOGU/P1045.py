from math import log10

a=int(input())

print(int(log10(2)*a+1))

b=str(pow(2,a)-1)
b=b.zfill(500)
for i in range(0,499,50):
    print(b[i:i+50])