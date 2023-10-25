n=int(input())

class user:
    def __init__(self, l):
        self.name = int(l[0])
        d = {}
        p=2
        for i in range(int(l[1])):
            d[l[p]] = l[p+1]
            p+=2
        self.data = d

l=[]

def operate(a):
    ret = set()
    flag = 0
    p = 2
    if a[0] == "|":
        flag +=1
        while (flag):
            p+=1
            if a[p] == "(":
                flag +=1
            elif a[p] == ")":
                flag -=1
        return operate(a[2:p]) | operate(a[p+2:-1])
    elif a[0] == "&":
        flag +=1
        while (flag):
            p+=1
            if a[p] == "(":
                flag +=1
            elif a[p] == ")":
                flag -=1
        return operate(a[2:p]) & operate(a[p+2:-1])
    else:
        # BASE_EXPR
        j=1
        while (a[j].isnumeric()):
            j+=1
        x=a[0:j]
        y=a[j+1:]
        if a[j]==":":
            for k in l:
                if k.data.get(x) == y:
                    ret.add(k.name)
        else:
            for k in l:
                try:
                    if k.data[x] != y:
                        ret.add(k.name)
                except:
                    pass
    return ret


for i in range(n):
    l.append(user(input().split()))

for i in range(int(input())):
    # a=input()
    k=sorted(operate(input()))
    for j in k:
        print(j, end=" ")
    print()