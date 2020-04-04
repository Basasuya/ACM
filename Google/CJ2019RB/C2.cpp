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

const int Maxn=110,Maxm=59;
class Simplex{
    public:
        static const double Inf;
        static const double eps;
    int n,m;
    double a[Maxn][Maxm];
    int Base[Maxm],Rest[Maxn];
    double val[Maxm];
    double ans;
    void pt(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)printf("%.2f ",a[i][j]);
            puts("");
        }
    }
    void pivot(int x,int y){//将第x个非基本变量和第y个基本变量调换
        swap(Rest[x],Base[y]);
        double tmp=-1./a[x][y];
        a[x][y]=-1.;
        for(int j=0;j<=m;j++)a[x][j]*=tmp;
        for(int i=0;i<=n;i++){
            if(i==x||fabs(a[i][y])<eps)continue;
            tmp=a[i][y];
            a[i][y]=0;
            for(int j=0;j<=m;j++)a[i][j]+=tmp*a[x][j];
        }
    }
    bool opt(){
        while(1){
            int csi=0;
            for(int i=1;i<=m;i++)if(a[0][i]>eps&&(!csi||Base[i]<Base[csi]))csi=i;
            if(!csi)break;
            int csj=0;
            double cur;
            for(int j=1;j<=n;j++){
                if(a[j][csi]>-eps)continue;
                double tmp=-a[j][0]/a[j][csi];
                if(!csj||tmp+eps<cur||(fabs(tmp-cur)<eps&&Rest[j]<Rest[csj]))csj=j,cur=tmp;
            }
            if(!csj)return 0;
            pivot(csj,csi);
        }
        ans=a[0][0];
        return 1;
    }
    bool init(){
        ans=0;
        for(int i=1;i<=m;i++)Base[i]=i;
        for(int i=1;i<=n;i++)Rest[i]=m+i;
        int cs=1;
        for(int i=2;i<=n;i++)if(a[i][0]<a[cs][0])cs=i;
        if(a[cs][0]>=-eps)return 1;
        static double tmp[Maxm];
        for(int i=0;i<=m;i++)tmp[i]=a[0][i],a[0][i]=0;
        for(int i=1;i<=n;i++)a[i][m+1]=1.;
        a[0][m+1]=-1.;Base[m+1]=m+n+1;
        pivot(cs,++m);
        opt();
        m--;
        if(a[0][0]<-eps)return 0;
        cs=-1;
        for(int i=1;i<=n;i++){
            if(Rest[i]>m+n){
                cs=i;
                break;
            }
        }
        if(cs>=1){
            int nxt=-1;
            m++;
            for(int i=1;i<=m;i++)if(a[cs][i]>eps||a[cs][i]<-eps){nxt=i;break;}
            pivot(cs,nxt);
            m--;
        }
        for(int i=1;i<=m;i++){
            if(Base[i]>m+n){
                swap(Base[i],Base[m+1]);
                for(int j=0;j<=n;j++)a[j][i]=a[j][m+1];
                break;
            }
        }
        for(int i=1;i<=m;i++)a[0][i]=0;a[0][0]=tmp[0];
        for(int i=1;i<=m;i++)if(Base[i]<=m)a[0][i]=tmp[Base[i]];
        for(int i=1;i<=n;i++){
            if(Rest[i]<=m){
                for(int j=0;j<=m;j++)a[0][j]+=tmp[Rest[i]]*a[i][j];
            }
        }
        return 1;
    }
    void getval(){
        for(int i=1;i<=m;i++)val[i]=0;
        for(int i=1;i<=n;i++)if(Rest[i]<=m)val[Rest[i]]=a[i][0];
        //for(int i=1;i<=m;i++)printf("%.2f ",val[i]);puts("");
    }
    int solve(){
        if(!init())return 0;
        if(!opt())return -1;
        getval();
        return 1;
    }
}solver;
const double Simplex:: Inf=1e80;
const double Simplex:: eps=1e-8;


const int MAXN = 305;
int C[MAXN], J[MAXN];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main() {   
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &C[i], &J[i]);
        }
        map<pair<ll, ll>, int> mp; 
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ll t1 = C[i] - C[j]; ll t2 = J[i] - J[j];
                if(1ll * t1 * t2 < 0) {
                    bool flag = true;
                    if(t1 < 0) flag = false;
                    t1 = abs(t1); t2 = abs(t2);
                    ll tmp = gcd(t1, t2);
                    t1 /= tmp;
                    t2 /= tmp;
                    if(flag) mp[make_pair(-t1, t2)] ++;
                    else mp[make_pair(t1, -t2)] ++;
                }
            }
        }
        // solver.a[0][0]=0;
        solver.n = (int)mp.size() + 2; solver.m = 2;
        int cnt = 0;
        solver.a[cnt][0] = 0; solver.a[cnt][1] = -1; solver.a[cnt][2] = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            cnt ++;
            ll t1 = (it->first).first; ll t2 = (it->first).second;
            solver.a[cnt][0] = -1;
            solver.a[cnt][1] = t1;
            solver.a[cnt][2] = t2;
            // printf("%lld %lld\n", t1, t2);
        }
        cnt ++; solver.a[cnt][0] = -1; solver.a[cnt][1] = 1; solver.a[cnt][2] = 0;
        cnt ++; solver.a[cnt][0] = -1; solver.a[cnt][1] = 0; solver.a[cnt][2] = 1;

        int rep = solver.solve();

        printf("Case #%d: ", cas);

        // debug(rep);
        if(rep == 0 || rep == -1) printf("IMPOSSIBLE\n");
        else {
            for(int i=1;i<=solver.m;i++)printf("%d%c",(int)solver.val[i],i==solver.m?'\n':' ');
        }
        
        
        


    }
    return 0;
}

/*


3
3
1 1
1 2
2 1
4
1 2
2 1
4 2
2 4
3
1 2
1 3
2 3

*/