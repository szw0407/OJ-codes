n,k = map(int, input().split())

var = set('0')
cnt = 0
for i in range(k):
    a, b = input().split()
    if b not in var:
        cnt += 1
    var.add(a)
print(cnt)
