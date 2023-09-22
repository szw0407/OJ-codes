class pile:
    weight:int
    price:int
    av:int
    def __init__(self, l):
        self.weight=l[0]
        self.price = l[1]
        self.av = l[1]/l[0]

n,t = map(int, input().split())
l=[]
for i in range(n):
    l.append(pile(list(map(int, input().split()))))
    l.sort(key=lambda pile:pile.av, reverse=True)

out = 0
w=0
for i in l:
    if (w+i.weight<=t):
        out += i.price
        w+=i.weight
    else:
        out += i.av*(t-w)
        break

print("%.2f" %(out))