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
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    cin>>a;
    vector<string> grid(n, string(n, '.'));

    grid[0][0] = 'X';
    auto checkcell = [&](int i,int j){
        int cnt = 0;
        if(i + 1 < n) cnt += (grid[i+1][j] == 'X');
        if(i - 1 >= 0) cnt += (grid[i-1][j] == 'X');
        if(j + 1 < n) cnt += (grid[i][j+1] == 'X');
        if(j - 1 >= 0) cnt += (grid[i][j-1] == 'X');
        if(cnt % 2 == 0) return false;
        return true;
    };
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(!checkcell(i-1, j)) grid[i][j] = 'X';
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 'X'){
                ans ^= a[i][j];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     printf("%s\n", grid[i].c_str());
    // }

    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}