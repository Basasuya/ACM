#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    pair<int, int> pos[n];
    for (int i = 0; i != n; ++i)
        cin >> pos[i].first >> pos[i].second;
    int c[n];
    for (int i = 0; i != n; ++i)
        cin >> c[i];
    int k[n];
    for (int i = 0; i != n; ++i)
        cin >> k[i];
    
    long long ans = 0;
    vector<int> power_plants;
    vector<pair<int, int>> connections;
    
    vector<bool> done(n);
    vector<int> parent(n, -1);
    for (int _n = n; _n--;)
    {
        int mi = 2000000000;
        int u = -1;
        for (int i = 0; i != n; ++i)
        {
            if (done[i])
                continue;
            
            if (c[i] < mi)
            {
                mi = c[i];
                u = i;
            }
        }
        
        ans += mi;
        done[u] = 1;
        if (parent[u] == -1)
            power_plants.push_back(u);
        else
            connections.push_back(make_pair(min(parent[u], u), max(parent[u], u)));
        
        for (int i = 0; i != n; ++i)
            if (1LL * (k[u] + k[i]) * (abs(pos[u].first - pos[i].first) + abs(pos[u].second - pos[i].second)) < c[i])
            {
                c[i] = (k[u] + k[i]) * (abs(pos[u].first - pos[i].first) + abs(pos[u].second - pos[i].second));
                parent[i] = u;
            }
    }
    
    cout << ans << '\n';
    cout << power_plants.size() << '\n';
    sort(power_plants.begin(), power_plants.end());
    for (int x : power_plants)
        cout << x + 1 << ' ';
    cout << '\n';
    cout << connections.size() << '\n';
    for (pair<int, int> x : connections)
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    
    return 0;
}