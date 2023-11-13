n,m = map(int, input().split())

opr = [0,0]
for i in range(n):
    dx, dy = map(int, input().split())
    opr[0] += dx
    opr[1] += dy

for i in range(m):
    x,y = map(int, input().split())

    print(x+opr[0], y+opr[1])