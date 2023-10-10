n=int(input())
data = {}
tot = 0
for i in range(n):
    for j in (input().split()):
        tot +=1
        if data.get(int(j)) is None:
            data[int(j)] = 1
        else:
            data[int(j)]+=1

key, value = sorted(data.items())[0]
for i in range(key, tot+key):
    if data.get(i) is None:
        print(i, end=" ")
        break

for i in range(key, tot+key):
    if data.get(i) == 2:
        print(i)
        break