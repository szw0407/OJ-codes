n,N = map(int, input().split())
a = []
for i in input().split():
    a.append(int(i))

r=N//(n+1)
tot = 0
tmp = 0
for i in range(1, N):
    if i in a:
        tmp += 1
    tot += abs(i//r - tmp)

print(tot)