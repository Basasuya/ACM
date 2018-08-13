#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int N = 1005;

struct Node{
    int id;
    int sum;
}E[N];
bool cmp(Node &a, Node &b) {
    if(a.sum != b.sum) return a.sum > b.sum;
    else return a.id < b.id;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            int a,b,c,d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            E[i].sum = a + b + c + d;
            E[i].id = i;
        }
        sort(E, E + n, cmp);
        int ans;
        for(int i = 0; i < n; ++i) {
            if(E[i].id == 0) {
                ans = i + 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
}