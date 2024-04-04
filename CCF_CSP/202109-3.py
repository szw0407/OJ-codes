N, S, P, T = map(eval, input().split())
dt = eval(input())
cnt = 0


class neu:
    def __init__(self, v, u, a, b, c, d):
        self.v = v
        self.u = u
        self.a = a
        self.b = b
        self.c = c
        self.d = d
        self.ed = []
        self.i = 0
        self.cnt = 0
        self.y = False

    def fv(self):
        v = self.v
        u = self.u
        i = self.i
        return v + dt * (0.04 * v**2 + 5 * v + 140 - u) + i

    def fu(self):
        u = self.u
        v = self.v
        a = self.a
        b = self.b
        return u + dt * a * (b * v - u)


class randcls:
    def __init__(self):
        self.next = 1
    def __iter__(self):
        return self
    def __next__(self):
        self.next = (self.next * 1103515245 + 12345) % (2**64)
        return (self.next // 65536) % 32768

myrand = randcls()
objs = []
while cnt < N:
    rn, v, u, a, b, c, d = map(eval, input().split())
    for _ in range(rn):
        objs.append(neu(v, u, a, b, c, d))
    cnt += rn


class src:
    def __init__(self, r):
        self.r = r
        self.ed = []
        self.y = False

for _ in range(P):  # source r and rand()
    objs.append(src(int(input())))


class con:
    def __init__(self, s, t, w, d):
        self.s = s
        self.t = t
        self.w = w
        self.queue = d * [False]
        


cons = []
for _ in range(S):
    s, t, w, D = map(eval, input().split())
    cons.append(con(s, t, w, D))
    objs[s].ed.append(_)

for time in range(T):
    for id in range(N, N + P):
        tmp = next(myrand)
        if tmp < objs[id].r:
            objs[id].y = True
            # for item in objs[id].ed:
            #     cons[item].queue[-1] = True

    for id in range(0, N):
        v1 = objs[id].fv()
        u1 = objs[id].fu()
        if v1 >= 30:
            objs[id].y = True
            # for item in objs[id].ed:
            #     cons[item].queue[-1] = True
            objs[id].u = u1 + objs[id].d
            objs[id].v = objs[id].c
            objs[id].cnt += 1
        else:
            objs[id].u = u1
            objs[id].v = v1
        objs[id].i = 0
    for item in range(S):
        cons[item].queue[-1] = (objs[cons[item].s].y)
        cons[item].queue.append(False)
        k = cons[item].queue.pop(0)     
        if k:
            objs[cons[item].t].i += cons[item].w
    for i in range(N+P):
        objs[i].y = False

objs = objs[:N]
print("%.3f %.3f" % (min(objs, key=lambda x: x.v).v, max(objs, key=lambda x: x.v).v))
print(min(objs, key=lambda x: x.cnt).cnt, max(objs, key=lambda x: x.cnt).cnt)
