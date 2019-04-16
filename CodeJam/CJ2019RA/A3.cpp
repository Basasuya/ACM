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
#include <string>
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


vector<pair<int, int> > result;

void solve2(pair<int, int> start, int weight) {
    pair<int, int> t1 = make_pair(start.first + 1, (weight + 2) / 2);
    pair<int, int> t2 = make_pair(start.first, 1);
    if(weight == 7 || weight == 8) {
        t1 = make_pair(start.first, 1);
        t2 = make_pair(start.first + 1, (weight + 2) / 2);
    }
    for(int i = 0; i < (weight + 1) / 2; ++i) {
        result.push_back(t1);
        result.push_back(t2);
        t1.second ++;
        t2.second ++;
    }

    t1 = make_pair(start.first + 1, 1);
    t2 = make_pair(start.first, (weight + 3) / 2);

    if(weight == 7 || weight == 8) {
        t1 = make_pair(start.first, (weight + 3) / 2);
        t2 = make_pair(start.first + 1, 1);
    }
    
    for(int i = 0; i < weight / 2; ++i) {
        result.push_back(t1);
        result.push_back(t2);
        t1.second ++;
        t2.second ++;
    }
} 



void solve3(pair<int, int> start, int weight) {
    pair<int, int> t1 = make_pair(start.first, 1);
    pair<int, int> t2 = make_pair(start.first + 1, 3);
    pair<int, int> t3 = make_pair(start.first + 2, 1);

    for(int i = 0; i < weight; ++i) {
        result.push_back(t1);
        result.push_back(t2);
        result.push_back(t3);
        t1.second ++;
        t2.second ++;
        if(t2.second > weight) t2.second = 1;
        t3.second ++;
    } 
} 



int main() {
    // freopen("in.txt", "r", stdin);
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {

        result.clear();
        int R, C;
        scanf("%d %d", &R, &C);
       
        
        int rotate = 0;
        if(R > C) {
            rotate = 1;
            swap(R, C);
        }
        printf("Case #%d: ", cas);
        if( (R == 3 && C == 3) || (R == 2 && C <= 4) ){
            printf("IMPOSSIBLE\n");
            continue;
        }

        if(R == 4 && C == 4) {
            printf("POSSIBLE\n");
            printf("1 1\n2 3\n3 1\n4 4\n3 2\n1 3\n2 1\n3 3\n1 2\n2 4\n4 1\n2 2\n3 4\n4 2\n1 4\n4 3\n");
            continue;
        }
        

        for(int i = 1; i <= R; i += 2) {
            if(R - i == 2) {
                solve3(make_pair(i, 1), C);
                i ++;
            } else solve2(make_pair(i, 1), C);
        }

        printf("POSSIBLE\n");
        
        
        // int bug = false;
        // int mp[25][25];
        // memset(mp, 0, sizeof(mp));
        // mp[result[0].first][result[0].second] = 1;
        // for(int i = 1; i < result.size() && !bug; ++i) {
        //     if( mp[result[i].first][result[i].second] == 1 ) 
        //         bug = true;
        //     if(result[i-1].first == result[i].first || result[i-1].second == result[i].second || (result[i-1].first + result[i-1].second == result[i].first + result[i].second) || (result[i-1].first - result[i-1].second == result[i].first - result[i].second) ) {
        //         printf("find in  %d %d %d\n", i, result[i].first, result[i].second);
        //         bug = true;
        //     }
        //     mp[result[i].first][result[i].second] ++;
        // }
        // if(bug) printf("there is a bug %d %d\n", R, C);

        
        
        for(int i = 0, len = result.size(); i < len; ++i) {
            if(rotate) printf("%d %d\n", result[i].second, result[i].first);
            else printf("%d %d\n", result[i].first, result[i].second);
        }
    }
    return 0;
}