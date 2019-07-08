#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        if(m >= n && k >= n) {
            printf("Yes\n");
        } else printf("No\n");

    }
    return 0;
}