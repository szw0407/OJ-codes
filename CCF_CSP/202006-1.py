n,m=map(int, input().split())

a = []
b = []

for _ in range(n):
    line = input().split()
    if line[-1] == 'A':
        a.append((int(line[0]), int(line[1])))
    else:
        b.append((int(line[0]),int(line[1])))
for _ in range(m):
    # a1+a2x+a3y=0
    a1,a2,a3 = map(eval, input().split())
    # f = False
    x,y = a[0]
    s = True
    f = a1 + a2 * x + a3 * y > 0
    for k in a[1:]:
        f1 = a1 + a2 * k[0] + a3 * k[1] > 0
        if f1 != f:
            s = False
            break
    if not s:
        print('No')
        continue
    for k in b:
        f1 = a1+ a2 * k[0] + a3 * k[1] > 0
        if f1 == f:
            s = False
            break
    if not s:
        print('No')
    else:
        print('Yes')
    
