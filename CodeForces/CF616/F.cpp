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

const int maxn = 30006;
int n,k;
int good[maxn];
void reset(){
    cout<<"R"<<endl;
}
bool query(int x){
    cout<<"? "<<x+1<<endl;
    string s;cin>>s;
    if(s[0]=='Y')return true;
    return false;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        good[i]=1;
    if(k==1){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                reset();
                query(i);
                if(query(j)){
                    good[j]=false;
                }
            }
        }
    }else{
        int block=k/2;
        int m=n/block;
        // for(int i = 0; i < m; ++i) {
        //     for(int j = i + 1; j < m; ++j) {
        //         reset();
        //         for(int x=i*block;x<(i+1)*block;x++){
        //             if(query(x)){
        //                 good[x]=false;
        //             }
        //         }
        //         for(int x=j*block;x<(j+1)*block;x++){
        //             if(query(x)){
        //                 good[x]=false;
        //             }
        //         }
        //     }
        // }

        for(int jump=1;jump<m;jump++){
            for(int start=0;start<jump&&start+jump<m;start++){
                reset();
                for(int i=start;i<m;i+=jump){
                    debug(i);
                    for(int x=i*block;x<(i+1)*block;x++){
                        if(query(x)){
                            good[x]=false;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(good[i])ans++;
    }
    cout<<"! "<<ans<<endl;
}