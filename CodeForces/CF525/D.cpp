#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
#include <unordered_map>
using namespace std;
const int N = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

typedef long long ll;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a = 0, b = 0;

    bool is_a = query(0, 0) == 1;

    for (int i = 29; i >= 0; i--) {
        int p = query(a, b | (1 << i));
        int q = query(a | (1 << i), b);

        if (p == -1 && q == 1) {
            a |= 0 << i;
            b |= 0 << i;
        } else if (p == 1 && q == -1) {
            a |= 1 << i;
            b |= 1 << i;
        } else {
            if (is_a) a |= 1 << i;
            else b |= 1 << i;

            is_a = p == 1;
        }
    }

    cout << "! " << a << " " << b << endl;

    return 0;
}