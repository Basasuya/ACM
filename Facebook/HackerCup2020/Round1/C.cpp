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

const int MAXN = 1e6 + 5;
int L[MAXN], H[MAXN], W[MAXN];
const int MOD = 1e9 + 7;

int main() {
    freopen("perimetric_chapter_3_input.txt", "r", stdin);
    freopen("perimetric_chapter_3_output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas){
        int N, K;
        int AL, BL, CL, DL;
        int AH, BH, CH, DH;
        int AW, BW, CW, DW;

        scanf("%d %d", &N, &K);

        for(int i = 0; i < K; ++i) {
            scanf("%d", &L[i]);
        }
        
        scanf("%d %d %d %d", &AL, &BL, &CL, &DL);

        for(int i = 0; i < K; ++i) {
            scanf("%d", &W[i]);
        }

        scanf("%d %d %d %d", &AW, &BW, &CW, &DW);

        for(int i = 0; i < K; ++i) {
            scanf("%d", &H[i]);
        }
        
        scanf("%d %d %d %d", &AH, &BH, &CH, &DH);

        for(int i = K; i < N; ++i) {
            L[i] = ( ( 1ll *AL * L[i - 2] + 1ll * BL * L[i - 1] + CL) % DL) + 1;
            W[i] = ( ( 1ll *AW * W[i - 2] + 1ll * BW * W[i - 1] + CW) % DW) + 1;
            H[i] = ( ( 1ll *AH * H[i - 2] + 1ll * BH * H[i - 1] + CH) % DH) + 1;
        }
        
        ll ans = 1;
        ll tmp_ans = 0;
        set<pair<int, int>> st;
        map<int, pair<int, int>> mp;

        mp[-1] = {0, 0};
        mp[INF] = {0, 0};

        auto Overlap = [](pair<int, int> X, pair<int, int> Y) -> bool { 
            if(X.first > Y.first) {
                swap(X, Y);
            }
            return Y.first >= X.first && Y.first <= X.second;
        };

        auto GetIntersection = [](pair<int, int> X, pair<int, int> Y) -> pair<int, int> {
            return make_pair(max(X.first, Y.first), min(X.second, Y.second));
        };

         auto GetUnion = [](pair<int, int> X, pair<int, int> Y) -> pair<int, int> {
            return make_pair(min(X.first, Y.first), max(X.second, Y.second));
        };

        // map<int, int> mp; 
        for(int i = 0; i < N; ++i) {
            if(i == 0) {
                tmp_ans += 2 * W[i] + 2 * H[i];
                st.insert({L[i], L[i] + W[i]});
                
                mp[L[i]] = {0, H[i]};
                mp[L[i] + W[i]] = {H[i], 0};

            } else {
                vector<pair<int, int>> remove_list;

                auto st_iter = st.lower_bound({L[i], -1});
                if(st_iter != st.begin()) st_iter --;        

                auto ed_iter = st.lower_bound({L[i] + W[i], -1});

                if(ed_iter == st.end()) --ed_iter;

                for(auto it = st_iter; ; ++it) {
                    int fr = (*it).first; int to = (*it).second;
                    if( Overlap({fr, to}, {L[i], L[i] + W[i]}) ) {
                        remove_list.push_back({fr, to});
                    }
                    if(it == ed_iter) break;
                }

                if(remove_list.empty()) {
                    tmp_ans += 2 * W[i] + 2 * H[i];
                    st.insert({L[i], L[i] + W[i]});

                    mp[L[i]] = {0, H[i]};
                    mp[L[i] + W[i]] = {H[i], 0};
                } else {
                    int sum_length = 0;
                    pair<int, int> section = {L[i], L[i] + W[i]};
                    for(auto it : remove_list) {
                        st.erase(it);
                        sum_length += it.second - it.first;
                        section = GetUnion(section, it);
                    }

                    {
                        auto start_it = mp.lower_bound(L[i]); --start_it;
                        auto end_it = mp.upper_bound(L[i] + W[i]);
                        
                        int fr = (start_it->second).second;
                        int to = (end_it->second).first;

                        ++ start_it;

                        while (start_it != end_it) {
                            tmp_ans = (tmp_ans - abs((start_it->second).second - (start_it->second).first) + MOD) % MOD;
                            start_it = mp.erase(start_it);
                        }

                        mp[L[i]] = {fr, H[i]};
                        tmp_ans = (tmp_ans + abs(H[i] - fr)) % MOD;

                        mp[L[i] + W[i]] = {H[i], to};
                        tmp_ans = (tmp_ans + abs(H[i] - to)) % MOD;
                    }

                    // debug(remove_list, section);

                    tmp_ans = (tmp_ans + 2 * (section.second - section.first - sum_length) % MOD) % MOD;
                    st.insert(section);
                }
            }
            tmp_ans %= MOD;
            ans = tmp_ans * ans % MOD;

            // debug(tmp_ans);
        }

        std::printf("Case #%d: %lld\n", cas, ans);
        fflush(stdout);
    }
}

/*

5
2 2
1 2
0 0 0 100
2 2
0 0 0 100
3 3
0 0 0 100
2 2
10 20
0 0 0 100
2 2
0 0 0 100
3 3
0 0 0 100
5 5
8 3 10 16 2
0 0 0 100
3 1 5 2 18
0 0 0 100
9 6 6 4 1
0 0 0 100
10 3
14 5 14
4 7 2 47
6 4 13
2 3 17 33
29 23 22
1 0 27 31
50 10
100 26 4 28 106 59 9 105 10 97
14 40 784 4832
130 12 82 487 12 30 214 104 104 527
21 81 410 605
938 903 899 899 896 857 841 837 834 834
1 0 924 951


*/