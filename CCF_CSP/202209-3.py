n=int(input())

p_rec= {}
u_vis= {}

for day in range(n):
    p = list(map(int, input().split()))
    r= p[0]
    m= p[1]
    p= p[2:]
    for i in p:
        if p_rec.get(i) is None or p_rec[i][1] < day - 1:
            p_rec[i] = [day, day+6]
        else:
            p_rec[i][1] = day+6
    for i in range(m):
        d,u,r = map(int, input().split())
        if p_rec.get(r) is None or not (p_rec[r][0] <= day <= p_rec[r][1]): # now the place is ok
            continue
        if p_rec[r][0] <= d <= p_rec[r][1]:  # the day visited is bad
            a = u_vis.get(u)
            if a:
                a[r] = max(d, a.get(r, -1))  # here!
            else:
                u_vis[u] = {r:d}
    users = sorted(u_vis.keys())
    print(day, end=' ')
    for i in users:
        flg = False
        for k,v in u_vis[i].items():
            if p_rec[k][0] <= v <= day <= p_rec[k][1] and day - v <=6:
                flg = True
        if flg:
            print(i, end=' ')
        else:
            u_vis.pop(i)
    print()
