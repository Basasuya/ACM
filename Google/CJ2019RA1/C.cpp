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




struct Trie{
	int cnt;
	Trie* nex[26];
};
Trie* root;

Trie* newNode() {
    Trie* tmp = new Trie();
    tmp->cnt = 0;
    return tmp;
}

void insert(char *seq) {
    Trie* rt = root;
    // cnt[rt] ++;
    for(int i = strlen(seq) - 1; i >= 0; --i) {
        int x = seq[i] - 'A';
        if(rt->nex[x] == NULL) {
            rt->nex[x] = newNode();
        }   
        rt = rt->nex[x];
        rt->cnt ++;
    }
}

int search(Trie* rt) {
    if(rt != root) {
        if(rt->cnt < 2) return 0;
        if(rt->cnt == 2) return 2;
    }
    int num = 0;
    for(int i = 0; i < 26; ++i) {
        if(rt->nex[i] != NULL) {
            num += search(rt->nex[i]);
        } 
    }
    return num + (rt->cnt- num >= 2) * 2;
}

int main() {
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        int n;
        scanf("%d", &n);
        root = newNode();
        for(int i = 0; i < n; ++i) {
            char a[55];
            scanf("%s", a);
            insert(a);
        }
        printf("Case #%d: ", cas);
        printf("%d\n", search(root));
    }
    return 0;
}

/*
4
2
TARPOL
PROL
3
TARPOR
PROL
TARPRO
6
CODEJAM
JAM
HAM
NALAM
HUM
NOLOM
4
PI
HI
WI
FI

*/