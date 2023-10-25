n=int(input())
num = "1"
ind = {}
for i in range(10):
    ind[str(i)] = str(2**i)
for i in range(n):
    res = ""
    for j in num:
        res += ind[j]
    num = res
b=input()
print(num.count(b)%998244353)