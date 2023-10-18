for i in range(int(input())):
    a=int(eval(input().replace("x", "*").replace("/","//")))
    print("Yes" if a==24 else "No")