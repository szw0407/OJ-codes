class endpoint:
    def __init__(self, id, area):
        self.id = id
        self.area = area
        self.task_list = []
    def add_task(self, task):
        self.task_list.append(task)
    def __lt__(self, other):
        return len(self.task_list) < len(other.task_list) if len(self.task_list) != len(other.task_list) else self.id < other.id
n,m = map(eval,input().split())
dir = [[] for i in range(m+1)]
l=list(map(int, input().split()))
k=[]
for i in range(n):
    tmp = endpoint(i+1, l[i])
    dir[l[i]].append(tmp)
    k.append(tmp)
g=int(input())

for i in range(g):
    f,a,na,pa,paa,paar = map(int, input().split())
    ep1=[]
    # filter
    for task in range(f):
        if (na!= 0):
            ep1 = dir[na].copy()
        else:
            ep1 = k.copy()
        ep2 = []
        if (pa!= 0):
            for eps in dir:
                for ep in eps:
                    if pa in ep.task_list and ep in ep1:
                        ep2.extend(eps)
                        break
        else:
            ep2 = ep1
        ep3 = []
        if (paa != 0):
            for j in ep2:
                if paa not in j.task_list:
                    ep3.append(j)
        else:
            ep3 = ep2
        if (len(ep3) == 0 and paar == 0):
            ep3 = ep2
        if len(ep3) == 0:
            print(0, end=" ")
        else:
            ep3.sort()
            print(ep3[0].id, end=' ')
            ep3[0].task_list.append(a)
    print()