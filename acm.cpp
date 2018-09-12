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
const int N = 1005;
const int INF = 0x3f3f3f3f;

int main(int argc, char** argv) {
    //   printf("%d\n", argc);
    if (argc == 1) {
        printf("missing cpp\n");
        exit(1);
    }
    if (argc > 2) {
        printf("too many parameter\n");
        exit(1);
    }
    string tt = "g++ ";
    tt += string(argv[1]);
    tt += ".cpp -o ";
    tt += string(argv[1]);
    tt += " -std=c++11";
    int t1 = system(tt.c_str());
}
