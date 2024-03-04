n,m = map(eval, input().split())
c = list(map(eval, input().split()))
a = list(map(eval, input().split()))

p = 0
count = 0
for j in range(n):
    if not len(a):
        break
    if c[0] <= a[0]:
        count += 1
        a.pop(0)
    c.pop(0)
    

print(count)