from math import factorial
for i in range(int(input())):
    a,b=map(int, input().split())
    print(str(factorial(a)).count(str(b)))