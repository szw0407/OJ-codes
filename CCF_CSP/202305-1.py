n=int(input())
rec = {}
for i in range(n):
    s = ""
    for j in range(8):
        s += input()
    if s not in rec.keys():
        rec[s] = 1
    else:
        rec[s] += 1
    print(rec[s])