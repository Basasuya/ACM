#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1


int mp[N];
int maxNum;
inline int read()
{
	int a = 0, c;
	do c = getchar(); while (!isdigit(c));
	while (isdigit(c)) {
		a = a*10+c-'0';
		c = getchar();
	}
	return a;
}


inline int Count(int k, int b, int x1, int x2, int y1, int y2) {
	int L = k*x1 + b;
	int R = k*x2 + b;
	if(L > R) swap(L, R);
	
	x1 = L; x2 = R;
	if(y1 < x1) {
		if(y2 < x1) return 0;
		else if(y2 <= x2) 
			return y2 - x1 + 1;
		else return x2 - x1 + 1;
	} else if(y1 <= x2) {
		return min(y2, x2) - y1 + 1;
	} else 
		return 0;
}
bool Test(int n, int m, int x) {
    
    if(n < 2*x-1 || m < 2*x-1)
        return false;
    int y = n + m - maxNum - x;
    if(y < x || m - y < x - 1) 
        return false;

//    printf("%d %d\n", n, m);
    for(int i = x; i <= maxNum; ++i) {
        int all = 0;
        int l1 = max(1, x - i);
        int l2 = min(n, x + i);
        int r1 = max(1, y - i);
        int r2 = min(m, y + i);

        all += Count(-1, i+x+y, l1, l2, r1, r2);
        all += Count(1, i-x+y, l1, l2, r1, r2);
        all += Count(-1, -i+x+y, l1, l2, r1, r2);
        all += Count(1, -i-x+y, l1, l2, r1, r2);
        all -= (n - x >= i) + (y > i) + (m - y >= i);

        if(all != mp[i])
            return false;
    }
    std::printf("%d %d\n%d %d\n", n, m, x, y);
    return true;
}
int main() {
    int t;
    t = read();
    maxNum = -1;
    for(int i = 0; i < t; ++i) {
        int x = read();
        mp[x] ++;
        maxNum = max(maxNum, x);
    }
    
    bool flag = true; int X;
    for(int i = 0; ; ++i) {
        int id = i; int num = mp[i];
        if(id == 0) {
            flag &= num == 1;
        } else {
            flag &= num == 4*i;
        }

        if(flag == false) {
            X = i;
            break;
        }
    }

    if(X == 0) {
        printf("-1\n");
        return 0;
    }
    flag = false;
    for(int i = 1; i <= sqrt(t) && !flag; ++i) {
        if(t % i == 0) {
            int n = i; int m = t / i;

            flag = Test(n, m, X);
            if(!flag) {
                flag = Test(m, n, X);
            }
        }
    }
    if(!flag) {
        printf("-1\n");
    }   
}