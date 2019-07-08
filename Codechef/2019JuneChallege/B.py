T=int(input())


while(True):
    n=int(input())
    k=int(input())
    
    p1 = k % n
    p2 = n - p1
    if(p1 == p2):
        print(p1 * 2 - 1)
    elif(p1 == 0):
        print(0)
    else:
        print(min(p1, p2) * 2)

    T -= 1
    if(T == 0):
        break