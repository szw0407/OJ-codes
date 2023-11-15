n,a,b= map(eval, input().split())

num = 0
for i in range(n):
    x1,y1,x2,y2 = map(eval, input().split())
    
    dx = min(x2,a) - max(x1,0) 
    
    dy = min(y2,b)- max(y1,0)
    if dx>0 and dy>0:
        num += dx*dy

print(num)
