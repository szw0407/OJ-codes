w,s = map(int, input().split())

k=1 # caps 1, alpha 2, num 3
num = []
for i in input():
    if i.isnumeric():
        if k==1:
            num.append(28)
        elif k==2:
            num.append(28)
        num.append(int(i))
        k=3
    elif i.isupper(): 
        if k==3:
            num.append(28)
        elif k==2:
            num.append(28)
            num.append(28)
        num.append(ord(i) - ord("A"))
        k=1
    else:
        if k==1:
            num.append(27)
        elif k==3:
            num.append(27)
        num.append(ord(i)-ord("a"))
        k=2
if len(num) %2 == 1:
    num.append(29)

res = [0]
for i in range(0, len(num), 2):
    res.append(num[i]*30+num[i+1])

LEN_OF_CHK = 2**(s+1) if s>=0 else 0
NUM_OF_900 = w-(len(res) + LEN_OF_CHK)%w
if NUM_OF_900 == w:
    NUM_OF_900 = 0
res.extend([900] * NUM_OF_900) # add 900s
res[0] = len(res)
for i in res:
    print(i)
if s >=0:
    g=[1]
    s=2**(s+1)
    res.extend([0] * s)
    for i in range(1, s+1):
        g.append(0)
        p = -3**(i)
        k = [i for i in g]
        for j in range(1, i+1):
            k[j] += p*g[j-1]
        g=k
    for i in range(res[0]):
        q = res[i]
        for j in range(len(g)):
            res[i+j] -= q*g[j]
            res[i+j] = res[i+j] % 929
        # ax**5+bx**4+cx**3+dx**2+e
        # x**2-12x+27
        # ax**3 
        # ax**5 - 12a x**4 + 27ax**3
        # (b+12a) x**4 + (c-27a) x**3 +dx**2+e
        # (b+12a) x**2 
        # (b+12a) x**4 - 12 * (b+12a) x**3 + 27 * (b+12a) x**2
        # 
    for i in range(-s, 0, 1):
        print(res[i])
