#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N = 505;

int x[N][N];
struct Node {
    int a, b, c, d;
    Node(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
};
vector<Node> vc;
int main() {
    int h, w;
    while (~scanf("%d %d", &h, &w)) {
        vc.clear();
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                scanf("%d", &x[i][j]);
            }
        }
        for (int i = 1; i <= h; ++i) {
            int fr = 1;
            int to = w;
            int add = 1;
            if (i % 2 == 0) {
                swap(fr, to);
                add = -1;
            }
            for (int j = fr;; j += add) {
                if (x[i][j] % 2) {
                    int t1 = i;
                    int t2 = j;
                    if ((j == 1 && add == -1) || (j == w && add == 1)) {
                        t1++;
                    } else
                        t2 += add;
                    if (t1 <= h) {
                        vc.push_back(Node(i, j, t1, t2));
                        x[i][j]--;
                        x[t1][t2]++;
                    }
                }
                if (j == to) break;
            }
        }
        printf("%d\n", (int) vc.size());
        for (auto &v : vc) {
            printf("%d %d %d %d\n", v.a, v.b, v.c, v.d);
        }
    }
    return 0;
}