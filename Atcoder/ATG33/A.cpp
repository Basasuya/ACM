#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int N = 1005;
char seq[N][N];
int step[N][N];
int dir[10][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };

int main() {
    int H, W;
    while(~scanf("%d %d", &H, &W)) {
        memset(step, 0, sizeof(step));

        for(int i = 1; i <= H; ++i) {
            scanf("%s", seq[i] + 1);
        }

        queue<pair<int, int> > Q;
        for(int i = 1; i <= H; ++i) {
            for(int j = 1; j <= W; ++j) {
                if(seq[i][j] == '#') {
                    step[i][j] = 1;
                    Q.push(make_pair(i, j));
                }
            }
        }

        int result = -1;
        while(!Q.empty()) {
            int x = Q.front().first; int y = Q.front().second; Q.pop();
            result = max(result, step[x][y]);

            for(int i = 0; i < 4; ++i) {
                int xx = x + dir[i][0]; int yy = y + dir[i][1];
                if(xx >= 1 && xx <= H && yy >= 1 && yy <= W && step[xx][yy] == 0) {
                    step[xx][yy] = step[x][y] + 1;
                    Q.push(make_pair(xx, yy));
                }
            }
        }

        printf("%d\n", result - 1);



        

        

    }
    return 0;
}