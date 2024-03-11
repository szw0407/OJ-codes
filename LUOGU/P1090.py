n=int(input())
a = list(map(int, input().split()))
f=0
while (len(a)>1):
    a.sort()
    # f+=a[0]
    k = a[0]+a[1]
    f+=k
    a.pop(0)
    a.pop(0)
    a.append(k)
# f+=min(a)
print(f)