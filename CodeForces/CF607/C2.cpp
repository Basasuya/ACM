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

const ll mod=1000000007;
const int MAXN=1000100;
// const int INF=1<<30;

int n,m;
char s[MAXN];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        scanf("%s",s);
        n=strlen(s);
        ll ans=n;
        for(int i=0;i<m;i++){
            int num=s[i]-'0';
            ll tem = (ans-i-1 + mod) % mod;
            ans=i+1;
            for(int j=0;j<num;j++){
                ans=(ans+tem)%mod;
            }
            // cout<<ans<<endl;
            int tem_n=n;
            if(n<m){
                for(int k=0;k<num-1;k++){
                    if(n>=m)break;
                    for(int j=i+1;j<tem_n;j++){
                        if(n>=m)break;
                        s[n++]=s[j];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }   
    return 0;
}