n,m,q=map(int,input().split())

class c:   # relation of oprations
    def __init__(self, a:list):
        self.name = a[0]
        nv=int(a[1])
        self.operate = [a[j+2] for j in range(nv)]
        no=int(a[2+nv])
        self.resource = [a[j+nv+3] for j in range(no)]
        nn = int(a[3+nv+no])
        self.resourceN = [a[j+nv+no+4] for j in range(nn)]
        self.userg = set()
        self.user = set()
    def bindusr(self, a:str):
        self.user.add(a)
    def bindusrg(self, g:str):
        self.userg.add(g)
        


ops = {}
ops_info = {"*":set()}
for i in range(n):
    a=input().split()
    ops[a[0]] = c(a)
    for j in ops[a[0]].operate:  # give operation names indexes
        if ops_info.get(j) is None:
            ops_info[j] = set([a[0]])
        else:
            ops_info[j].add(a[0])

for i in range(m):
    a=input().split()
    for j in range(2, len(a)-1, 2):  # bind operations relations with users and user groups
        if a[j] == "g":
            ops[a[0]].bindusrg(a[j+1])
        else:
            ops[a[0]].bindusr(a[j+1])

for i in range(q):
    a=input().split()
    name = a[0]
    opr_name = a[-3]
    all_retations_names = set(ops_info["*"])
    try:
        all_retations_names.update(ops_info[opr_name])
    except:
        pass

    user_group = set(a[2:-3])
    allowed_users = set()
    allowed_usergs = set()
    flag = 0
    relation_to_be_checked = []
    for j in all_retations_names:
        if name in ops[j].user:
            flag = 1
            relation_to_be_checked.append(ops[j])
        elif user_group & ops[j].userg:
            flag = 1
            relation_to_be_checked.append(ops[j])
    
    if flag == 0:
        print(0)
        continue
    flag = 0
    for j in relation_to_be_checked:
        if a[-2] in j.resource or "*" in j.resource:
            if a[-1] in j.resourceN or j.resourceN.__len__() == 0:
                flag = 1
                break
    print(flag)


    