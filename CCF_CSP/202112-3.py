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