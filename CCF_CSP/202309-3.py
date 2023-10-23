n,m = map(int, input().split())

t=[0] * (n + 1)  # exps of each var in polynomial

line = input().split()

stack = []

def add(a, b):
    ret = {}
    keys = set(a.keys()) | set(b.keys())
    common = set(a.keys()) & set(b.keys())
    for i in keys:
        if i in common:
            ret[i] = a[i] + b[i]
        elif i in a:
            ret[i] = a[i]
        else:
            ret[i] = b[i]
    return ret

def mul(a, b):
    ret = {}
    for i in a.keys():
        for j in b.keys():
            t=tuple(i[k] + j[k] for k in range(len(i)))
            if ret.get(t) is None:
                ret[t] = a[i] * b[j]
            else:
                ret[t] += a[i] * b[j]
    return ret

for l in line:        
    if l == "*":
        a=stack.pop()
        b=stack.pop()
        stack.append(mul(a,b))
    elif l == "+":
        a=stack.pop()
        b=stack.pop()
        stack.append(add(a,b))
    elif l == "-":
        a=stack.pop()
        b=stack.pop()
        for k,v in a.items():
            a[k] = -v
        stack.append(add(a, b))
    elif l[0] == 'x':
        num = int(l[1:])
        t[num] = 1
        stack.append({tuple(t):1})
        t[num] = 0
    else:  # const 
        stack.append({tuple(t):int(l)})

b = {k: v for k, v in stack[0].items() if v != 0}  # remove term == 0

def partial_derivative(poly, var):
    result = {}
    for key, value in poly.items():  # check all items in the polynomial
        exps = list(key)
        exp = exps[var]  # the exp of the var
        if exp != 0:  # otherwise is 0
            coef = value * exp
            exps[var] -= 1
            result[tuple(exps)] = coef
    return result

def evaluate_poly(poly, values):
    result = 0
    for key, value in poly.items():
        exps = list(key)
        t = value
        for i in range(1,len(values)):
            if exps[i] != 0:
                t *= int(values[i]) ** int(exps[i])
        result += t
    return result

for _ in range(m):
    temp = input().split()
    print(evaluate_poly(partial_derivative(b, int(temp[0])), temp)%1000000007)