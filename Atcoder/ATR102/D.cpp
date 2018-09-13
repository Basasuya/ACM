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
struct Node{
    int a, b, c;
    Node(int _a=0, int _b=0, int _c=0):a(_a), b(_b), c(_c) {}
};

vector<Node> vc;
int main() {
    int L;

    while (~scanf("%d", &L)) {
        vc.clear();
        int tmp = L;
        int cnt1 = 0; 
        while(tmp) {
            tmp /= 2;
            cnt1 ++;
        }

        for(int i = 1; i < cnt1; ++i) {
            vc.push_back(Node(i, i + 1, 0));
            vc.push_back(Node(i, i + 1, 1<<(i-1)));
        }

        tmp = L; 
        bool flag = true;
        int tmp2 = 0;
        for(int i = cnt1 - 1; i >= 0; --i) {
            if( (tmp >> i) & 1 ) {
                tmp -= 1 << i;
                if(!flag) {
                    vc.push_back(Node(i+1, cnt1, tmp2));
                }
                tmp2 += 1 << i;
                flag = false;
            }
        }

        printf("%d %d\n", cnt1, (int)vc.size());
        for(int i = 0; i < (int)vc.size(); ++i) {
            printf("%d %d %d\n", vc[i].a, vc[i].b, vc[i].c);
        }
    }
    return 0;
}