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
using namespace std;

const int MAXN = 1e5 + 5;

char seq[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        // scanf("%d %s", &n, seq);
        scanf("%s",seq);
        n = strlen(seq);
        int firstZero = -1; int zeroCnt = 0;

        for(int i = 0; i < n; ++i) {
            if(seq[i] == '0') {
                if(firstZero == -1) firstZero = i;
                zeroCnt ++;
            }
        }

        if(firstZero == -1) printf("%s\n", seq);
        else if(zeroCnt == 1) printf("%s\n", seq);
        else {
            for(int i = 0; i < n; ++i) seq[i] = '1';
            seq[firstZero + zeroCnt - 1] = '0'; 
            printf("%s\n", seq);
        }

    }
    return 0;
}

/*




100
2
10
4
0001

*/