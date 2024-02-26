n=int(input())
m = []
for _ in range(1, n+1):
    a, b, g, k = map(int, input().split())
    m.append((a, b, a+g-1, b+k-1))

x,y = map(int, input().split())
o = -1
k=1
for j in m:
    if j[0]<=x<=j[2] and j[1] <= y <= j[3]:
        o = k
    k+=1
print(o)