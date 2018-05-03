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
const int N = 1000005;
char s[1000005];

map<string, int> StoI;
vector<string> ItoS;
int tot = 0;
vector<int> result;
vector<int> E[N][2];
int tag[N][2];
int vis[N][2];

void dfs(int x, int flag) {
    vis[x][flag] = 1;
    tag[x][flag]++;
    // printf("%d %d %s\n", x, flag, ItoS[x].c_str());
    for (int i = 0, len = E[x][flag].size(); i < len; ++i) {
        int to = E[x][flag][i];
        if (vis[to][flag ^ 1])
            continue;
        dfs(to, flag ^ 1);
    }
}
int main() {
#ifdef LOCAL
    freopen("/Users/basasuya/ACM/in.txt", "r", stdin);
#endif
    int cnt = 0;
    while (1) {
        s[cnt++] = getchar();
        if (s[cnt - 1] == -1 || s[cnt - 1] == '\n') {
            s[cnt - 1] = 0;
            break;
        }
    }
    int sLen = strlen(s);
    string tmp;
    ItoS.push_back(".");
    for (int i = 0; i < sLen; ++i) {
        if (s[i] == ' ' || s[i] == '.' || s[i] == ',') {
            if (!tmp.empty()) {
                if (StoI.find(tmp) == StoI.end()) {
                    ++tot;
                    StoI[tmp] = tot;
                    ItoS.push_back(tmp);
                }
                int Id = StoI[tmp];
                result.push_back(Id);
            }
            if (s[i] == '.')
                result.push_back(0);
            else if (s[i] == ',')
                result.push_back(-1);
            tmp.clear();
        } else
            tmp += s[i];
    }
    for (int i = 0, len = result.size(); i < len; ++i) {
        if (i >= 1 && result[i - 1] > 0 && result[i] > 0) {
            E[result[i - 1]][0].push_back(result[i]);
            E[result[i]][1].push_back(result[i - 1]);
        } else if (i >= 2 && result[i - 2] > 0 && result[i] > 0 && result[i - 1] == -1) {
            E[result[i - 2]][0].push_back(result[i]);
            E[result[i]][1].push_back(result[i - 2]);
            tag[result[i - 2]][0]++;
            tag[result[i]][1]++;
        }
    }
    for (int i = 1; i <= tot; ++i) {
        if (!vis[i][0] && tag[i][0]) {
            dfs(i, 0);
        }
        if (!vis[i][1] && tag[i][1]) {
            dfs(i, 1);
        }
    }

    for (int i = 0, len = result.size(), ok = 0; i < len; ++i) {
        if (i && result[i - 1] > 0 && result[i] > 0 && (tag[result[i - 1]][0] || tag[result[i]][1]))
            printf(",");
        if (result[i] < 0)
            printf(",");
        else if (result[i] == 0)
            printf(".");
        else {
            if (i)
                printf(" ");
            printf("%s", ItoS[result[i]].c_str());
        }
    }
}
