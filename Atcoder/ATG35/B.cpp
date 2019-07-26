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

const int MAXN = 1e5 + 5;

// int a[MAXN];
// int b[MAXN];

// struct Node{
//     int fr, to, nx, dis;
// }E[N << 1];
// int head[N]; int tot = 0; 
// void add(int fr, int to) {
//     E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
// }

set<int> st[MAXN];
int cnt[MAXN];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            st[i].clear();
            cnt[i] = 0;
        }
        

        set<pair<int, int> > Q;

        for(int i = 0; i < m; ++i) {
            int fr, to;
            scanf("%d %d", &fr, &to);
            st[fr].insert(to);
            st[to].insert(fr);
        }

        if(m % 2 == 1) {
            printf("-1\n");
            continue;
        }

        for(int i = 1; i <= n; ++i) {
            Q.insert(make_pair(st[i].size(), i));
        }

        vector<pair<int, int> > result;

        while(!Q.empty()) {
            pair<int, int> tmp = *Q.begin(); int t1 = tmp.first; int t2 = tmp.second;
            // printf("hh: %d %d\n", t1, t2);
            Q.erase(tmp);
            int start = 0;
            if( (st[t2].size() + cnt[t2]) % 2 == 1 ) start ++;
            vector<int> deleteArr;
            // bool flag = true;
            for(auto it : st[t2]) {
                deleteArr.push_back(it);
            }
            int choose;
            if(!deleteArr.empty())
                choose = rand() % (int)deleteArr.size();
            int count = 0;
            for(auto it : deleteArr) {
                
                if(start && (count == choose) ) { 
                    // flag = false; 
                    st[t2].erase(it);
                    st[it].erase(t2);
                    result.push_back(make_pair(it, t2));
                    if(st[it].size() > 0) {
                        Q.erase(make_pair(st[it].size() + 1, it));
                        Q.insert(make_pair(st[it].size(), it));
                    }
                    cnt[it] ++;
                    count ++;
                    continue; 
                }
                count ++;

                st[t2].erase(it);
                st[it].erase(t2);
                result.push_back(make_pair(t2, it));
                if(st[it].size() > 0) {
                    Q.erase(make_pair(st[it].size() + 1, it));
                    Q.insert(make_pair(st[it].size(), it));
                }
                // cnt[it] ++;
            }

        }


        for(int i = 0, len = result.size(); i < len; ++i) {
            printf("%d %d\n", result[i].first, result[i].second);
        }
    }
    return 0;
}


/*
5 4
1 2
1 3
1 4
4 5

4 4
1 2
2 3
3 4
4 1

6 10
1 2
2 3
3 4
4 5
5 6
6 1
1 4
2 5
2 4
6 3
 */