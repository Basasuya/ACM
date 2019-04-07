
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 1300
#define mod 100000000

struct bignumber {
    int n;
    int a[maxn];
    void clear() {
        n = 0;
        memset(a, 0, sizeof(a));
    }
    void init(char *s) {
        clear();
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            int num = (len + 7 - i) / 8;
            a[num] = a[num] * 10 + (s[i] - '0');
        }
        n = (len + 7) / 8;
    }
    void output() {
        printf("%d", a[n]);
        for (int i = n - 1; i >= 1; i--) printf("%08d", a[i]);
        printf("\n");
    }
    int operator<(bignumber b) {
        if (n < b.n) return 1;
        if (n > b.n) return 0;
        for (int i = n; i > 0; i--) {
            if (a[i] < b.a[i]) return 1;
            if (a[i] > b.a[i]) return 0;
        }
        return 0;
    }
    int operator==(bignumber b) {
        if (n != b.n) return 0;
        for (int i = n; i > 0; i--)
            if (a[i] != b.a[i]) return 0;
        return 1;
    }
    int operator<=(bignumber b)  //>返回0，<返回2，=返回1
    {
        if (n < b.n) return 2;
        if (n > b.n) return 0;
        for (int i = n; i > 0; --i) {
            if (a[i] > b.a[i]) return 0;
            if (a[i] < b.a[i]) return 2;
        }
        return 1;
    }
};
bignumber operator+(bignumber a, bignumber b) {
    a.n = max(a.n, b.n);
    for (int i = 1; i <= a.n; i++) {
        a.a[i] += b.a[i];
        a.a[i + 1] += a.a[i] / mod;
        for (; a.a[i] >= mod; a.a[i] -= mod)
            ;
    }
    if (a.a[a.n + 1] > 0) a.n++;
    return a;
}
bignumber operator-(bignumber a, bignumber b) {
    for (int i = 1; i <= a.n; i++) {
        a.a[i] -= b.a[i];
        if (a.a[i] < 0) {
            a.a[i + 1]--;
            a.a[i] += mod;
        }
    }
    while (a.a[a.n] == 0 && a.n > 1) a.n--;
    return a;
}
bignumber operator*(bignumber a, int b) {
    for (int i = 1; i <= a.n; i++) {
        a.a[i] = a.a[i] * b + a.a[i - 1] / mod;
        for (; a.a[i - 1] >= mod; a.a[i - 1] -= mod)
            ;
    }
    while (a.a[a.n] >= mod) {
        a.n++;
        a.a[a.n] = a.a[a.n - 1] / mod;
        for (; a.a[a.n - 1] >= mod; a.a[a.n - 1] -= mod)
            ;
    }
    return a;
}
bignumber operator/(bignumber a, int b) {
    int tmp = 0;
    for (int i = a.n; i > 0; i--) {
        tmp = tmp * mod + a.a[i];
        a.a[i] = tmp / b;
        tmp %= b;
    }
    while (a.a[a.n] == 0 && a.n > 1) a.n--;
    return a;
}

bignumber gcd(bignumber a, bignumber b) {
    int ans = 0;
    bignumber c;
    while (1) {
        if (a.n == 1 && a.a[1] == 0) {
            c = b;
            break;
        }
        if (b.n == 1 && b.a[1] == 0) {
            c = a;
            break;
        }
        int flag = 0;
        if (a.a[1] % 2 == 0) a = a / 2, flag++;
        if (b.a[1] % 2 == 0) b = b / 2, flag++;
        if (flag == 2) ans++;
        if (!flag)
            if (a < b)
                b = b - a;
            else
                a = a - b;
    }
    while (ans--) c = c * 2;
    return c;
}


bignumber a1,b1,c1;  
char aa[10100],bb[10100];  
int main()  
{  
  
    scanf("%s%s",aa,bb);  
    a1.init(aa);  
    b1.init(bb);  
    c1=gcd(a1,b1);  
    c1.output();  
    return 0;  
} 