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

// int tick[405];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
        for(int i = 0; i < 4 * n; ++i) {
            int x; scanf("%d", &x);
            mp[x] ++;
        }
        vector<pair<int, int> > vc;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            vc.push_back(make_pair(it->first, it->second));
        }
        bool flag = true;
        int pre = -1;
        int len = vc.size();
        for(int i = 0; i < len / 2 && flag; ++i) {
            pair<int, int> fr = vc[i];
            pair<int, int> ed = vc[len - i - 1];
            if(pre == -1) pre = fr.first * ed.first;
            else  flag &= (fr.first * ed.first == pre);
            flag &= fr.second == ed.second;
            flag &= fr.second % 2 == 0;
        }
        if(len % 2 == 1) {
            pair<int, int> fr = vc[len / 2];
            if(pre != -1) flag &= (fr.first * fr.first == pre);
            flag &= fr.second % 4 == 0;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}