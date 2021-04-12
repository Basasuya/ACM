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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Matrix{
	int a[10][10];
	int n;
	Matrix(int _n=0){
		memset(a,0,sizeof(a));
		n = _n;
	}
	Matrix operator *(const Matrix &T) const{
		Matrix ans = Matrix(n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					ans.a[i][j] = (ans.a[i][j] + 1ll*a[i][k]*T.a[k][j]%MOD) % MOD;
                }
            }
            break;
        }	
		return ans;
	}
};

Matrix operator ^(Matrix x,int y){
	Matrix ans = Matrix(x.n);
	for(int i = 0; i < x.n; ++i) ans.a[i][i] = 1;
	while(y){
		if(y&1) ans=ans*x;
		y >>= 1; x = x*x;
	}
	return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        Matrix init = Matrix(10);

        while(n) {
            init.a[0][n % 10] ++;
            n /= 10;
        }

        Matrix solve = Matrix(10);
        for(int i = 0; i < 10; ++i) {
            solve.a[(i + 9) % 10][i] = 1;
        }

        solve.a[9][1] = 1;

        Matrix ans = (init * solve) ^ m;

        ll result = 0;
        for(int i = 0; i < 10; ++i) {
            result = (result + ans.a[0][i]) % MOD;
        }

        printf("%lld\n", result);
    }
    return 0;
}  