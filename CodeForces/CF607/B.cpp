#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MP make_pair
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define bitCount(a)  __builtin_popcount(a)
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
const int INF = 0x3f3f3f3f;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


char seqA[5005], seqB[5005];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s %s", seqA, seqB);
        string A = seqA;
        string B = seqB;
        bool suc = false;
        
        int n = strlen(seqA);
        int m = strlen(seqB);

        vector<int> cnt(30, 0);

        if(A < B) {
            printf("%s\n", A.c_str());
            continue;
        }

        for(int i = 0; i < n; ++i) {
            cnt[A[i] - 'A'] ++;
        }

        bool ok = false;
        for(int i = 0; i < min(n, m); ++i) {
            cnt[A[i] - 'A'] --;
            int minChar = INF;
            
            for(int j = 0; j < 26; ++j) {
                if(cnt[j]) {
                    minChar = j;
                    break;
                }
            }

            debug(i, minChar);

            if(minChar < A[i] - 'A') {
                int pos = -1;
                for(int j = i + 1; j < n; ++j) {
                    if( (A[j] - 'A') == minChar) {
                        pos = j; 
                    }
                }

                string C = A;
                swap(C[i], C[pos]);

                if(C < B) {
                    printf("%s\n", C.c_str());
                    suc = true;
                } else printf("---\n");
                ok = true;
                break;
            } else if(A[i] > B[i]) {
                ok = true;
                printf("---\n");
                break;
            }
            
        }

        if(ok == false) printf("---\n");



        // int min_Char = 30; int min_Pos = -1; int not_min_Pos = -1;
        // for(int i = 0; i < n; ++i) {
        //     if( (A[i] - 'A') <= min_Char ) {
        //         min_Char = (A[i] - 'A');
        //         min_Pos = i;
        //     }
        // }

        // for(int i = 0; i < n; ++i) {
        //     if( (A[i] - 'A') != min_Char ) {
        //         not_min_Pos = i; 
        //         break;
        //     }
        // }

        // if(not_min_Pos == -1) {
        //     printf("---\n");
        //     continue;
        // }

        // string C = A;
        // swap(C[min_Pos], C[not_min_Pos]);

        // if(C < B) {
        //     printf("%s\n", C.c_str());
        //     suc = true;
        // } else printf("---\n");


        // for(int i = 0; i < n && !suc; ++i) {
        //     if(A[i] == B[i]) continue;

        //     for(int j = 0; j < n && !suc; ++j) {
        //         string C = A;
        //         swap(C[i], C[j]);

        //         if(C < B) {
        //             printf("%s\n", C.c_str());
        //             suc = true;
        //         }
        //     }
        // }

        // if(suc == false) printf("---\n");
    }
    return 0;
}