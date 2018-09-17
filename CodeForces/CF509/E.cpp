#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int f[200009];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == n || b != n) {
            cout << "NO" << endl;
            return 0;
        }
        f[a]++;
        f[b]++;
    }
    int k = n;
    vector<int> v;
    vector<pair<int, int> > ans;
    for (int i = 1; i <= n - 1; i++) {
        if (f[i] == 0) {
            v.push_back(i);
        } else {
            if (v.size() < f[i] - 1) {
                cout << "NO" << endl;
                return 0;
            }
            vector<int> C;
            C.push_back(n);

            int x = f[i] - 1;
            while (x--) {
                C.push_back(v.back());
                v.pop_back();
            }
            C.push_back(i);
            for (int i = 1; i < C.size(); i++) ans.push_back({C[i - 1], C[i]});
        }
    }
    if (v.size()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}