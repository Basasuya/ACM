import math

x = -1
y = -1
def exgcd(a, b):
    global x, y
    if(b == 0):            
        x=1
        y=0
        return a
    r = exgcd(b, a%b)
    t = y
    y = x-(a//b)*y  
    x = t
    return r

def gcd(x0, y0):
    if(y0 == 0):
        return x0
    else:
        return gcd(y0, x0 % y0)

def solve():
    n, p, w, d = [int(tt) for tt in input().split()]
    # print(n,p,w,d)
    tmp = gcd(w, d)
    if(p % tmp != 0):
        print("-1")
        return
        
    r = exgcd(w, d)

    minT = math.ceil(-p * y / w)
    maxT = math.floor(p * x / d)
    print(maxT)
    maxT = min(maxT, math.floor( (n * r - p * x - p * y) // (w - d) ))
    print(maxT)
    if(maxT < minT):
        print("-1")
        return
    print((n * r - p * x - p * y))
    # print(p,w,d,x,y,tmp, r, minT)
    # target = (minT + maxT) // 2
    target = maxT
    _x = (p * x - d * target) // r 
    _y = (p * y + w * target) // r
    _z = n - _x - _y
    print(_x, _y, _z)




if __name__ == "__main__":
    solve()