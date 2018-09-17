#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int a[N];
struct Node {
    int a, b, c;
    Node(int _a, int _b, int _c) : a(_a), b(_b), c(_c){};
};

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

        vector<Node> vc;
        vector<int> Zero;
        int cntNeg = 0;
        int tagNeg;
        int minNeg = -INF;
        int cntZero = 0;
        int tagZero;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) {
                cntNeg++;
                if (minNeg < a[i]) {
                    minNeg = a[i];
                    tagNeg = i;
                }
            } else if (a[i] == 0) {
                Zero.push_back(i);
                cntZero++;
            }
        }

        if (cntNeg % 2) {
            if (cntZero)
                vc.emplace_back(1, tagNeg, Zero[0]);
            else
                vc.emplace_back(2, tagNeg, 0);
        }

        for (int i = 0; i < (int) Zero.size() - 1; ++i) {
            vc.emplace_back(1, Zero[i], Zero[i + 1]);
        }
        if (cntZero) {
            vc.emplace_back(2, Zero[Zero.size() - 1], 0);
        }

        int pre = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != 0 && !(i == tagNeg && cntNeg % 2)) {
                if (pre != -1) vc.emplace_back(1, pre, i);
                pre = i;
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (vc[i].c == 0) {
                printf("%d %d\n", vc[i].a, vc[i].b);
            } else
                printf("%d %d %d\n", vc[i].a, vc[i].b, vc[i].c);
        }
    }
    return 0;
}