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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b > a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b < a)a = b; }
#define MS(x, y) memset(x, y, sizeof(x))

struct Node{
    int num, id;
    Node(int a, int b):num(a), id(b){}
    void Print() { printf("%d %d\n", num, id); }
    bool operator < (const Node& T) const{
        return num > T.num;
    }
};

int mp[N][4][4];
// int row[N][4][2];
int rowFull[4][15];
// int col[N][4][2];
int colFull[4][15];



int main() {
    int n;
    while(~scanf("%d", &n)) {
        priority_queue<Node> Q[4][4];
        // Q[0][0].push(Node(3,1));
        // Q[0][0].push(Node(5,1));
        // Q[0][0].push(Node(2,1));
        // while(!Q[0][0].empty()) {
        //     Node tt = Q[0][0].top(); Q[0][0].pop();
        //     tt.Print();
        // }
        // printf("%d\n", n);
        // memset(row, 0, sizeof(row));
        // memset(col, 0, sizeof(col));
        
        memset(rowFull, 0, sizeof(rowFull));
        memset(colFull, 0, sizeof(colFull));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 4; ++j) {
                for(int z = 0; z < 4; ++z) {
                    scanf("%d", &mp[i][j][z]);
                }
            }
        }
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                Q[i][j].push(Node(0, -1)); Q[i][j].push(Node(0, -2));
            }
        }
        // printf("hhhh\n");
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 4; ++j) {
                int cnt1 = 0; int cnt2 = 0;
                for(int z = 0; z < 4; ++z) {
                    if(mp[i][j][z] == 1) {
                        cnt1 ++;
                    } else break;
                }
                for(int z = 3; z > -1; --z) {
                    if(mp[i][j][z] == 1) {
                        cnt2 ++;
                    } else break;
                }
                
                if(cnt1 == 4) rowFull[j][0] ++;
                else {
                    Q[0][j].push(Node(cnt1, i));
                    Q[1][j].push(Node(cnt2, i));
                    if(Q[0][j].size() > 2) Q[0][j].pop();
                    if(Q[1][j].size() > 2) Q[1][j].pop();
                }
            }
        }
        for(int j = 0; j < 4; ++j) {
            Node t1 = Q[0][j].top(); Q[0][j].pop(); Node t2 = Q[0][j].top(); 
            Node t3 = Q[1][j].top(); Q[1][j].pop(); Node t4 = Q[1][j].top(); 
            int tt = 0;
            if(t2.id == t4.id) {
                tt = max(t1.num + t4.num, t2.num + t3.num);
            } else tt = t2.num + t4.num;
            gmax(ans, rowFull[j][0] * 4 + tt);
        }

        // int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 4; ++j) {
                int cnt1 = 0; int cnt2 = 0;
                for(int z = 0; z < 4; ++z) {
                    if(mp[i][z][j] == 1) {
                        cnt1 ++;
                    } else break;
                }
                for(int z = 3; z > -1; --z) {
                    if(mp[i][z][j] == 1) {
                        cnt2 ++;
                    } else break;
                }
                
                if(cnt1 == 4) colFull[j][0] ++;
                else {
                    // printf("%d %d\n", cnt1, cnt2);
                    Q[2][j].push(Node(cnt1, i));
                    Q[3][j].push(Node(cnt2, i));
                    if(Q[2][j].size() > 2) Q[2][j].pop();
                    if(Q[3][j].size() > 2) Q[3][j].pop();
                }
            }
        }

        for(int j = 0; j < 4; ++j) {
            Node t1 = Q[2][j].top(); Q[2][j].pop(); Node t2 = Q[2][j].top(); Q[2][j].pop();
            Node t3 = Q[3][j].top(); Q[3][j].pop(); Node t4 = Q[3][j].top(); Q[3][j].pop();
            int tt = 0;
            if(t2.id == t4.id) {
                tt = max(t1.num + t4.num, t2.num + t3.num);
            } else tt = t2.num + t4.num;
            // t1.Print();  t2.Print(); t3.Print(); t4.Print();
            // printf("%d\n", tt);
            gmax(ans, colFull[j][0] * 4 + tt);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
1 0 1 0 
0 0 1 0 
1 0 1 0 
0 1 0 1 

1 0 1 0 
0 1 1 1 
1 0 1 1 
1 1 1 0 

1 0 1 1 
0 1 0 0 
0 1 0 0 
0 0 0 1 

3
1 0 1 0 
0 0 1 0 
1 0 1 1
0 1 0 1 

1 0 1 0 
0 1 1 1 
1 1 1 1 
1 1 1 0 

1 0 1 1 
0 1 0 0 
1 1 1 1
0 0 1 1 

3
1 1 1 1 
0 0 1 1 
1 0 1 1 
0 1 1 1 

1 1 1 1 
0 0 1 1 
1 0 1 1 
0 1 1 1 

1 1 1 1 
0 0 1 1 
1 0 1 1 
0 1 1 1 

*/