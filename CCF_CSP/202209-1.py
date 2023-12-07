n,m = map(int, input().split())

d = list(map(int, input().split()))

c = [1]

for i in d:
    c.append(c[-1] * i)

out = [0] * n

for i in range(n-1, -1, -1):
    out[i] = m // c[i]
    m -= out[i] * c[i]

print(' '.join(str(i) for i in out))