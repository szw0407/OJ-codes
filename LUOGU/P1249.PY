a=int(input())
b=[]
c=0
i=1


def CalcM(s):
    n=len(s)
    res=1
    for i in range(n):
        res=res*s[i]
    return res
def CalcA(s):
    n=len(s)
    res=0
    for i in range(n):
        res=res+s[i]
    return res
while(c<a):
    i=i+1
    b.append(i)
    c=c+i
ed=i-2
if(c==a):
    k=CalcM(b)
else:
    b.remove(c-a)
    k=CalcM(b)
for i in range(len(b)-1):
    print(b[i],end=" ")
print(b[i+1])
print(k)