n=int(input())
arg  ={}
front = 0
for _ in range(n):
    scr, res = map(int, input().split())
    if res:
        if arg.get(scr) is None:
            arg[scr] = -1
        else:
            arg[scr] -= 1
        front += 1
    else:
        if arg.get(scr) is None:
            arg[scr] =1
        else:
            arg[scr] += 1

is_first = True
for scr in sorted(arg.keys()):
    if is_first:
        res = scr
        max_cnt = front
        front += arg[scr]
        is_first = False
        continue
    
    if front >= max_cnt:
        res = scr
        max_cnt = front
    front += arg[scr]

print(res)