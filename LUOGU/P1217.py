a,b = map(int, input().split())
l=set()

def isPrime(x):
    if x<2:
        return False
    elif x==2:
        return True
    for i in range(2,int(x**0.5)+2):
        if (x%i==0):
            return False
    return True

for i in range(1,10000,1):
    stri = str(i)
    tmp = int(stri + stri[::-1])
    if isPrime(tmp):
        l.add(tmp)
    tmp = int(stri + stri[-2::-1])
    if isPrime(tmp):
        l.add(tmp)
for i in sorted(l):
    if i in range(a,b+1):
        print(i)