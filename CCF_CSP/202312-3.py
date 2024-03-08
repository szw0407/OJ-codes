n,m = map(int, input().split())
w_bk = [0] + list(map(int, input().split()))
p = [0, 0] + list(map(int, input().split()))

for i in range(m):
    sum_w = [0]*(n+1)
    id = int(input())
    rem = set(range(1,n+1))
    w = w_bk.copy()
    tot = sum(w)
    s_node = [set() for _ in range(n+1)]
    for j in range(1,1+n):
        tmp = j
        while True:
            sum_w[tmp] += w[j]
            s_node[tmp].add(j)
            if tmp > 1:
                tmp = p[tmp]
            else:
                break
    ex = {}
    while len(rem) > 1:
        for _ in sorted(rem):
            ex[_] = abs(tot - 2 * sum_w[_])
        min_j = min(ex, key=ex.get)
        print(min_j, end=' ')
        if id not in s_node[min_j]:
            rem = rem - s_node[min_j]
            tmp = p[min_j]
            while True:
                sum_w[tmp] -= sum_w[min_j]
                s_node[tmp] -= s_node[min_j]
                if tmp == 1:
                    break
                tmp = p[tmp]
        else:
            rem = s_node[min_j]
        tot = sum(w[_] for _ in rem)
        ex = {}
    print()
