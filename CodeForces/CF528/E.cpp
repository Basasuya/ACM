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
#include <assert.h>
#include <iomanip>
#include <unordered_map>
using namespace std;
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char s[N], a[N], b[N];
int hasFrom[30];
int hasTo[30];
int k; 

bool judge(int type, int pos) {
    if(type) {
        int len = strlen(s);
        for(int i = pos + 1; i < len; ++i) {
            if(hasFrom[s[i] - 'a'] == -1) {
                bool flag = false;
                for(int j = 0; j <= a[i] - 'a'; ++j) {
                    if(hasTo[a[i] - 'a']) {
                        hasTo[a[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[a[i] - 'a'];
                        if(j < a[i] - 'a') return true;
                        flag = true;
                        break;
                    }
                }

                if(!flag) return false;
            } else {
                if(hasFrom[s[i] - 'a'] > a[i] - 'a') return true;
                else if(hasFrom[s[i] - 'a'] < a[i] - 'a') return false;
            }
        }
    } else {
        int len = strlen(s);
        for(int i = pos + 1; i < len; ++i) {
            if(hasFrom[s[i] - 'a'] == -1) {
                bool flag = false;
                for(int j = k - 1; j >= b[i] - 'a'; --j) {
                    if(hasTo[b[i] - 'a']) {
                        hasTo[b[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[b[i] - 'a'];
                        if(j > b[i] - 'a') return true;
                        flag = true;
                        break;
                    }
                }

                if(!flag) return false;
            } else {
                if(hasFrom[s[i] - 'a'] < b[i] - 'a') return true;
                else if(hasFrom[s[i] - 'a'] > b[i] - 'a') return false;
            }
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        memset(hasFrom, -1, sizeof(hasFrom));
        memset(hasTo, -1, sizeof(hasTo));

        scanf("%d", &k);
        scanf("%s %s %s", s, a, b);

        bool suc = true;
        for(int len = strlen(s), i = 0; i < len && suc; ++i) {
            if(a[i] == b[i]) {
                if(hasFrom[s[i] - 'a'] == -1) {
                    if(hasTo[a[i] - 'a'] != -1 && hasTo[a[i] - 'a'] != s[i] - 'a') suc = false;
                    else {
                        hasTo[a[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[a[i] - 'a'];
                    }
                } else {
                    if(hasFrom[s[i] - 'a'] != a[i] - 'a') suc = false;
                    else {
                        hasTo[a[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[a[i] - 'a'];                        
                    }
                }  
            } else if(b[i] - a[i] > 1){
                int tt = b[i] - 1 - 'a';

                if(hasFrom[s[i] - 'a'] == -1) {
                    bool flag = false;
                    for(int j = a[i] - 'a' + 1; j < b[i] - 'a' + 1; ++j) {
                        if(hasTo[j] == -1) {
                            hasTo[j] = s[i] - 'a';
                            hasFrom[s[i] - 'a'] = hasTo[j];     
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                    else {
                        if(hasTo[a[i] - 'a'] == -1) {
                            hasTo[a[i] - 'a'] = s[i] - 'a';
                            hasFrom[s[i] - 'a'] = hasTo[a[i] - 'a'];     
                            bool tag = judge(1, i);
                            if(tag) break;
                            hasFrom[s[i] - 'a'] = -1;
                            hasTo[a[i] - 'a'] = -1;
                        }


                        if(hasTo[b[i] - 'a'] == -1) {
                            hasTo[b[i] - 'a'] = s[i] - 'a';
                            hasFrom[s[i] - 'a'] = hasTo[b[i] - 'a'];     
                            bool tag = judge(0, i);
                            if(tag) break;
                            hasFrom[s[i] - 'a'] = -1;
                            hasTo[b[i] - 'a'] = -1;
                        }
                    }
                } else {
                    int t1 = hasFrom[s[i] - 'a'];
                    if(t1 < a[i] - 'a' || t1 > b[i] - 'a') suc = false;
                }  
            } else {
                if(hasFrom[s[i] - 'a'] == -1) {
                    if(hasTo[a[i] - 'a'] == -1) {
                        hasTo[a[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[a[i] - 'a'];     
                        bool tag = judge(1, i);
                        if(tag) break;
                        hasFrom[s[i] - 'a'] = -1;
                        hasTo[a[i] - 'a'] = -1;
                    }


                    if(hasTo[b[i] - 'a'] == -1) {
                        hasTo[b[i] - 'a'] = s[i] - 'a';
                        hasFrom[s[i] - 'a'] = hasTo[b[i] - 'a'];     
                        bool tag = judge(0, i);
                        if(tag) break;
                        hasFrom[s[i] - 'a'] = -1;
                        hasTo[b[i] - 'a'] = -1;
                    }
                } else {
                    if(hasFrom[s[i] - 'a'] == a[i] - 'a') {
                        bool tag = judge(1, i);
                        if(tag) break;
                    }


                    if(hasFrom[s[i] - 'a'] == b[i] - 'a') {
                        bool tag = judge(0, i);
                        if(tag) break;
                    } 
                }
            }
        }

        if(!suc) printf("NO\n");
        else {
            vector<int> t1, t2;
            for(int i = 0; i < k; ++i) {
                if(hasFrom[i] == -1) t1.push_back(i);
            }
            for(int i = 0; i < k; ++i) {
                if(hasTo[i] == -1) t2.push_back(i);
            }

            for(int i = 0, len = t1.size(); i < len; ++i) {
                hasFrom[t1[i]] = t2[i]; 
                hasTo[t2[i]] = t1[i]; 
            }

            for(int i = 0; i < k; ++i) printf("%d ", hasTo[i]); printf("\n");
        }

    }
    return 0;
}