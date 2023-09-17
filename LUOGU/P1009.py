n=int(input())

def calc_multiply(n):
    m=1
    for i in range(1,n+1,1):
        m=m*i
    return m
S=0

for i in range(1,n+1,1):
    S+=calc_multiply(i)

print(S)