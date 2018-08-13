#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long
const int maxn = 100000 + 100;
struct Point {
    LL x, y;
    Point() {}
    Point(LL xx, LL yy) {
        x = xx;
        y = yy;
    }
};

LL operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

bool operator<(const Point &a, const Point &b) {
    return a.x == b.x? a.y < b.y: a.x < b.x;
}

LL operator^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

struct Cross_len {
    LL cross, len;
};

bool operator==(const Cross_len &a, const Cross_len &b) {
    return a.cross == b.cross && a.len == b.len;
}

bool operator!=(const Cross_len &a, const Cross_len &b) {
    return !(a == b);
}

int n[2], top[2];
Point point[2][maxn], sta[2][maxn << 1];
int Next[maxn];
Cross_len cross_len[2][maxn << 1];

void ConvexHull(Point *p, int n, int &top, Point *sta) {
    top = 0;
    sort(p + 1, p + 1 + n);
    for(int i = 1; i <= n; ++i) {
        while(top > 1 && ((sta[top - 1] - sta[top - 2]) ^ (p[i] - sta[top - 2])) <= 0) {
            --top;
        }
        sta[top++] = p[i];
    }
    int ttop = top;
    for(int i = n; i > 0; --i) {
        while(top > ttop && ((sta[top - 1] - sta[top - 2]) ^ (p[i] - sta[top - 2])) <= 0) {
            --top;
        }
        sta[top++] = p[i];
    }
    --top;
}

void Change_to_Cross_len(Point *p, int n, Cross_len *c) {
    // for(int i = 0; i < n; ++i) {
    //     printf("%lld %lld / ", p[i].x, p[i].y);
    // }
    // printf("\n");

    Point p0 = p[0];
    for(int i = 0; i < n - 1; ++i) {
        p[i] = p[i + 1] - p[i];
        c[i].len = p[i] * p[i];
    }
    p[n - 1] = p0 - p[n - 1];
    c[n - 1].len = p[n - 1] * p[n - 1];
    for(int i = 0; i < n; ++i) {
        c[i].cross = (p[i] * p[(i + 1) % n]) + (p[i] ^ p[(i + 1) % n]);
    }

    // for(int i = 0; i < n; ++i) {
    //     printf("%lld %lld /%lld %lld: ", p[i].x, p[i].y, c[i].cross, c[i].len);
    // }
    // printf("\n");
}

void get_next(Cross_len *str, int n) {
    int j = -1;
    Next[0] = -1;
    for(int i = 1; i < n; ++i) {
        while(j != -1 && str[j + 1] != str[i]) {
            j = Next[j];
        }
        if(str[i] == str[j + 1]) {
            ++j;
        }
        Next[i] = j;
    }
}

bool kmp(Cross_len *str1, int n, Cross_len *str2, int m) {
    int j = -1;
    for(int i = 0; i < n; ++i) {
        while(j != -1 && str1[i] != str2[j + 1]) {
            j = Next[j];
        }
        if(str1[i] == str2[j + 1]) {
            ++j;
        }
        if(j == m - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    while(scanf("%d%d", &n[0], &n[1]) != EOF) {
        memset(point, 0, sizeof(point));
        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= n[i]; ++j) {
                scanf("%lld%lld", &point[i][j].x, &point[i][j].y);
            }
            ConvexHull(point[i], n[i], top[i], sta[i]);
            if(i == 0) {
                for(int j = 0; j < top[i]; ++j) {
                    sta[i][j + top[i]] = sta[i][j];
                }
                top[i] *= 2;
            }
            Change_to_Cross_len(sta[i], top[i], cross_len[i]);
        }
        get_next(cross_len[1], top[1]);
        if(kmp(cross_len[0], top[0], cross_len[1], top[1])) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}