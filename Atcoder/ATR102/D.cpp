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

int two[25];
int main() {
    int L;
    two[0] = 1;
    for (int i = 1; i < 25; ++i) two[i] = two[i - 1] * 2;
    while (~scanf("%d", &L)) {
        printf("20 38\n");

        for (int i = 1; i < 20; ++i) {
            printf("%d %d %d\n", i, i + 1, 0);
            printf("%d %d %d\n", i, i + 1, two[i]);
        }
    }
    return 0;
}