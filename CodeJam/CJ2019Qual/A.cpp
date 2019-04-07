#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
// #include <assert.h>
#include <iomanip>
using namespace std;
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;


char num[105];
char a[105];
char b[105];
int main() {
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        scanf("%s", num);

        bool flag = true;
        for(int i = 0, len = strlen(num); i < len; ++i) {
            if(num[i] == '4') {
                a[i] = '2';
                b[i] = '2';
                flag = false;
            } else {
                a[i] = num[i];
                b[i] = '0';
            }
        }

        if(flag == true) {
            int pos = -1;
            
            for(int i = strlen(num) - 1; i >= 0; --i) {
                if(num[i] != '0') {
                    pos = i;
                    // if(num[i] == '1') {
                    //     hasOne = true;
                    // }
                    break;
                }
            }
            int hasOne = false; 
            for(int i = 0, len = strlen(num); i < len; ++i) {
                if(i < pos) {
                    a[i] = num[i];
                    b[i] = '0';
                } else if(i == pos) {
                    if(num[i] == '5') {
                        a[i] = '3';
                        b[i] = '2';
                    } else if(num[i] == '1' && i != strlen(num) - 1) {
                        a[i] = '0';
                        b[i] = '0';
                        hasOne = true;
                    } else {
                        a[i] = num[i] - 1;
                        b[i] = '1';
                    }
                } else {
                    if(hasOne) {
                        a[i] = '9';
                        b[i] = (i == strlen(num) - 1) ? '1' :'0';
                    } else {
                        a[i] = num[i];
                        b[i] = '0';
                    }
                }
            }
        }

        printf("Case #%d: ", cas);
        for(int i = 0, len = strlen(num), flag = true; i < len; ++i) {
            if(a[i] == '0' && flag) {
            } else {
                flag = false;
                printf("%c", a[i]);
            }
        }
        printf(" ");
        for(int i = 0, len = strlen(num), flag = true; i < len; ++i) {
            if(b[i] == '0' && flag) {
            } else {
                flag = false;
                printf("%c", b[i]);
            }
        }
        printf("\n");
    
    }
    return 0;
}


/*


100
4
940
4444
100000000000000
200000000000000
*/