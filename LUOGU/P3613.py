# 最近有段时间没写C++了，只记得Python咋写的了

n, q = map(int, input().split())
db = {}
for _ in range(q):
    ip = input().split()
    if ip[0] == '1':
        tmp=db.get(ip[1])
        if not tmp:
            tmp = {}
            db[ip[1]] = tmp
        tmp[ip[2]] = ip[3]
    else:
        print(db[ip[1]][ip[2]])

