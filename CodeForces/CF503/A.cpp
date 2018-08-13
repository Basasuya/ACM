#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int main() {
    int n, h, a, b, k;
    auto Abs = [](int x) {
        return x > 0? x: (-x);
    };
    while(~scanf("%d %d %d %d %d", &n, &h, &a, &b, &k)) {
        for(int i = 0; i < k; ++i) {
            int t1, f1, t2, f2;
            scanf("%d %d %d %d", &t1, &f1, &t2, &f2);
            int Floor = min(max(min(f1, f2), a), b);
        //    printf("hh: %d\n", Floor);
            printf("%d\n", t1 == t2? Abs(f1- f2) : Abs(Floor - f1) + Abs(t2 - t1) + Abs(Floor - f2));
        }
    }
    return 0;
}