#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int N = 131073;

int A[N];
int T[N];
int main() {
    int n, x;
    while(~scanf("%d %d", &n, &x)) {
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            int t; scanf("%d", &t);
            T[i] = t;
        }
        for(int i = 0; i < n; ++i) {
            A[T[i]] ++;
            if(A[T[i]] == 2) {
                ans = 0;
                break;
            }
        }
        
        if(ans == -1) {
            for(int i = 0; i < n; ++i) {
                if(A[T[i] & x] == 1 && ( (T[i] & x) != T[i])) {
                    ans = 1;
                    break;
                }
            }
        }

        if(ans == -1) {
            for(int i = 0; i < n; ++i) {
                A[T[i]] --;
            }
            for(int i = 0; i < n; ++i) {
                A[T[i] & x] ++;
                if(A[T[i] & x] == 2) {
                    ans = 2;
                    break;
                }
            }
        }

        printf("%d\n", ans);
    }   
    return 0;
}