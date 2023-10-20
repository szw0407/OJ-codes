from functools import cmp_to_key

n=int(input())
PSlist={"BangZhu":0,"FuBangZhu":1,"HuFa":2,"ZhangLao":3,"TangZhu":4,"JingYing":5,"BangZhong":6}
class person():
    name=None
    position=None
    BG=None
    level=None
    num=None
    def __init__(self,n,k):
        self.name=n[0]
        self.position=n[1]
        self.BG=int(n[2])
        self.level=int(n[3])
        self.num=k

def cmpOfPerson(a,b):
    if (a.num<=2 or b.num<=2):
        return 0
    tmp = b.BG-a.BG
    return tmp
def cmpOfList(a,b):
    if (a.num<=2 or b.num <=2):
        return 0
    tmp=PSlist[a.position]-PSlist[b.position]
    if (tmp==0):
        tmp=b.level-a.level
    if (tmp==0):
        tmp=a.num-b.num
    return tmp

ls=[None]*n
for i in range(n):
    ls[i]=person(input().split(" ",3),i)
ls.sort(key=cmp_to_key(cmpOfPerson))
ps=["BangZhu","FuBangZhu","FuBangZhu","HuFa","HuFa","ZhangLao","ZhangLao","ZhangLao","ZhangLao","TangZhu","TangZhu","TangZhu","TangZhu","TangZhu","TangZhu","TangZhu"]
for i in range(25):
    ps.append("JingYing")
for i in range(len(ls)):
    try:
        ls[i].position=ps[i]
    except:
        ls[i].position="BangZhong"

ls.sort(key=cmp_to_key(cmpOfList))
for i in range(len(ls)):
    print(ls[i].name,ls[i].position,ls[i].level)