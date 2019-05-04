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


char seq[105];
int cnt[30];
int main() {
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%s", seq);
        memset(cnt, 0, sizeof(cnt));
        vector<int> solve;
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            cnt[seq[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; ++i) {
            if(cnt[i])
                solve.push_back(i);
        }

        string result; result.clear();
        if(solve.size() == 3) {
            // if(solve.size() == 1)  
            if(abs(solve[0] - solve[1]) == 1) {
                for(int j = 0; j < cnt[solve[0]]; ++j) {
                    result += solve[0] + 'a';
                }
                for(int j = 0; j < cnt[solve[2]]; ++j) {
                    result += solve[2] + 'a';
                }
                for(int j = 0; j < cnt[solve[1]]; ++j) {
                    result += solve[1] + 'a';
                }
            } else {
                for(int j = 0; j < cnt[solve[1]]; ++j) {
                    result += solve[1] + 'a';
                }
                for(int j = 0; j < cnt[solve[0]]; ++j) {
                    result += solve[0] + 'a';
                }
                for(int j = 0; j < cnt[solve[2]]; ++j) {
                    result += solve[2] + 'a';
                }
            }
        } else {     
            for(int i = 1, len = solve.size(); i < len; i += 2) {
                for(int j = 0; j < cnt[solve[i]]; ++j) {
                    result += solve[i] + 'a';
                }
            } 

            for(int i = 0, len = solve.size(); i < len; i += 2) {
                for(int j = 0; j < cnt[solve[i]]; ++j) {
                    result += solve[i] + 'a';
                }
            } 
        }

        bool suc = true;
        for(int i = 1, len = result.length(); i < len && suc; ++i) {
            if( abs(result[i-1] - result[i]) == 1) suc = false;
        }



        if(!suc) printf("No answer\n");
        else printf("%s\n", result.c_str());

        
    }
    return 0;    
}