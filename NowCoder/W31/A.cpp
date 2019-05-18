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
// #define ll long long
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


using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
#define x1 Duliu
#define x2 Daduliu
typedef __int128 LL;
int T;
ll n,coef;
LL f1,f2,x1;
inline LL f(LL x) {
    return (LL)x*x*x-(LL)coef*x;
}
inline void Recur(LL x) {
    if(x>9)
        Recur(x/10);
    printf("%d",(int)(x%10));
}
inline void Wrote(LL x) {
    if(!x) {
        printf("0");
        return;
    }
    Recur(x);
}
int main() {
    for(read(T);T--;) {
        read(n),coef=n*3-2,f1=1e36,f2=-1e36;
        if(f((n&1)-2)>0)
            f1=min(f1,f((n&1)-2));
        x1=ceil(-sqrt(coef)),
        x1+=((x1&1)^(coef&1)),
        x1+=(!f(x1))*2,
        f1=min(f1,x1<0?f(x1):f1),
        x1=ceil(sqrt(coef)),
        x1+=((x1&1)^(coef&1)),
        x1+=(!f(x1))*2,
        f1=min(f1,f(x1)),
        x1=floor(-sqrt(coef/3)),
        x1-=((x1&1)^(coef&1)),
        f2=max(f2,f(x1)),
        x1=ceil(-sqrt(coef/3)),
        x1+=((x1&1)^(coef&1)),
        f2=max(f2,f(x1)),
        Wrote(f1/6),putchar(' '),Wrote(f2/6),puts("");
    }
}