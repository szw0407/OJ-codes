n,a,b = map(int, input().split())

u = {}

res = 0
for _ in range(a):
    id , val = map(int, input().split())
    u[id] = val

for _ in range(b):
    id, val = map(int, input().split())
    try:
        res += u[id] * val
    except:
        pass

print(res)