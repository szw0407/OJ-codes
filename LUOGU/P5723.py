def isPrime(x):
    if x<2:
        return False
    elif x==2:
        return True
    for i in range(2,int(x**0.5)+2):
        if (x%i==0):
            return False
    return True

if __name__ == "__main__":
    lim = int(input())
    k=2
    sum=0
    num=0
    while (True):
        if isPrime(k):
            sum += k
            if (sum > lim):
                break
            else:
                print(k)
                num+=1
        k = k+1
    print(num)