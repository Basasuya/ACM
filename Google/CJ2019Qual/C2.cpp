#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;


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

bignumber operator/(bignumber a, bignumber b) {
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
bignumber seq[105];
bignumber prime[105];
// ll tag[105];
vector<bignumber> num;
int main() {
    
    // while(1) {
    //     ll a, b;
    //     scanf("%lld %lld", &a, &b);
    //     printf("%lld\n", gcd(a, b));
    // }
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        char tmp[105];
        // memset(tag, 0, sizeof(tag));
        num.clear();
        int n, l;
        scanf("%d %d", &n, &l);
        
        for(int i = 0; i < l; ++i) {
            scanf("%s", &tmp);
            seq.init(tmp);
        }

        int pos = -1;
        for(int i = 1; i < l; ++i) {
            if(seq[i] != seq[i-1]) {
                // tag[i] = 1;
                prime[i] = gcd(seq[i], seq[i-1]);
                pos = i;
                break;
            }
        }
        
        // for(int i = 1; i < l; ++i) {
        //     if(tag[i] == 1) {
        //         pos = i;
        //     }
        // }
        
        for(int i = pos - 1; i >= 0; --i) {
            prime[i] = seq[i] / prime[i + 1];
        }
        for(int i = pos + 1; i <= l; ++i) {
            prime[i] = seq[i-1] / prime[i-1];
        }

        // prime[0] = seq[0] / prime[1];
        // prime[l] = seq[l - 1] / prime[l-1];

        for(int i = 0; i <= l; ++i) {
            num.push_back(prime[i]);
        }
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        
        // assert(num.size() == 26);
        // printf("%d\n", (int)num.size());
        // for(int i = 0, len = num.size(); i < len; ++i) printf("%lld ", num[i]); printf("\n");
  

        printf("Case #%d: ", cas);

        for(int i = 0; i <= l; ++i) {
            int tt = lower_bound(num.begin(), num.end(), prime[i]) - num.begin();
            printf("%c", tt + 'A');
        } printf("\n");
    
    }
    return 0;
}

/*
2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543

  


Output 
 
Case #1: CJQUIZKNOWBEVYOFDPFLUXALGORITHMS
Case #2: SUBDERMATOGLYPHICFJKNQVWXZ




*/
