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

const int MAXN = 1e5 + 5;
int isPrime[MAXN]; 
int Prime[MAXN];
int primeTot;

int main() {
    primeTot = 0;
    for(int i = 2; i < MAXN; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < MAXN; j += i) {
            isPrime[j] = 1;
        }
    }

    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);

        vector<int> divisor;
        for(int i = 2; i <= sqrt(n); ++i) {
            if(n % i == 0) {
                divisor.push_back(i);
                if(1ll * i * i != n) divisor.push_back(n / i);
            }
        }
        divisor.push_back(n);

        sort(divisor.begin(), divisor.end());

        vector<pair<int, int> > prime;
        vector<vector<int>> prime_vc;
        // set<int> prime_set;

        {
            int tmp = n;
            for(int i = 1; i <= primeTot; ++i) {
                if(tmp == 1) break;
                if(tmp % Prime[i] == 0) {
                    int cnt = 0;
                    while(tmp % Prime[i] == 0) {
                        cnt ++;
                        tmp /= Prime[i];
                    }
                    prime.push_back({Prime[i], cnt});     
                    // prime_set.insert(Prime[i]);       
                }
            }
            
            // debug(divisor.size(), divisor, prime);

            if(tmp != 1) {
                prime.push_back({tmp, 1});  
                // prime_set.insert(tmp);
            }
        }

        sort(prime.begin(), prime.end());

        prime_vc.resize(prime.size(), vector<int>());

        debug(prime);

        if(prime.size() == 1) {
            for(int i = 0, len = divisor.size(); i < len; ++i) {
                if(i) printf(" ");
                printf("%d", divisor[i]);
            }
            printf("\n0\n");
            continue;
        }

        if(prime.size() == 2 && prime[0].second + prime[1].second == 2) {
            printf("%d %d %d\n1\n", prime[0].first, prime[0].first * prime[1].first, prime[1].first);
            continue;
        }

        int not_contain_cnt = 0;
        for(int i = 0, len = divisor.size(); i < len - 1;  ++i) {
            for(int j = 0, len2 = prime.size(); j < len2; ++j) {
                if(divisor[i] % prime[j].first == 0) {
                    if(j == len2 - 1 || divisor[i] / prime[j].first != prime[j + 1].first) {
                        prime_vc[j].push_back(divisor[i]);
                    }
                    break;
                }
            }
        }

        // debug(prime_vc, prime_set);

        // debug(not_contain_cnt, prime_set);

        for(int i = 0, len = prime.size(); i < len; ++i) {
            if(i) printf("%d ", prime[i].first * prime[i - 1].first);
            for(auto ele : prime_vc[i]) {
                assert(ele);
                printf("%d ", ele);
            }
        }

        printf("%d\n0\n", divisor.back());
    }
    return 0;
}