#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 6e5+5;
#define MS(x,y) memset(x,y,sizeof(x))
#define MP(x, y) make_pair(x, y)
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

std::set<pair<int, int> > unExistedMap;
int nextPoint[N];
int prePoint[N];
class List {
   public:
    int headPoint;
    void initialize(int n) {
        headPoint = 1;
        for (int i = 1; i <= n; ++i) {
            nextPoint[i] = i + 1;
            prePoint[i] = i - 1;
        }
        nextPoint[n] = 0;
        prePoint[1] = 0;
    }
    void deletePoint(int pos) {
        int prePos = prePoint[pos];
        int nexPos = nextPoint[pos];
        nextPoint[prePos] = nexPos;
        prePoint[nexPos] = prePos;
        if (prePos == 0)
            headPoint = nexPos;
    }

   public:
    List(int n) { initialize(n); }
    vector<int> Solve() {
        vector<int> result;
        while (1) {
            if (headPoint == 0)
                break;
            std::queue<int> bfsQueue;
            bfsQueue.push(headPoint);
            deletePoint(headPoint);
            int totalMapSeg = 0;
            while (!bfsQueue.empty()) {
                totalMapSeg++;
                int nowPoint = bfsQueue.front();
                bfsQueue.pop();
                for (int i = headPoint; i; i = nextPoint[i]) {
                    int from = nowPoint;
                    int to = i;
                    if (from > to)
                        swap(from, to);
                    if (unExistedMap.find(std::make_pair(from, to)) == unExistedMap.end()) {
                        bfsQueue.push(i);
                        deletePoint(i);
                    }
                }
            }
            result.push_back(totalMapSeg);
        }
        return result;
    }
};

int main() {
    int n, m, k;
    while (~scanf("%d %d %d", &n, &m, &k)) {
        int cntOne = 0;
        unExistedMap.clear();
        // result.clear();
        for (int i = 0; i < m; ++i) {
            int from, to;
            scanf("%d %d", &from, &to);
            if (from > to)
                swap(from, to);
            if(from == 1) {
                cntOne ++;
            }
            unExistedMap.insert(std::make_pair(from, to));
        }

        List Basa = List(n);
        vector<int> result1 = Basa.Solve();

        Basa = List(n);
        Basa.deletePoint(1);
        vector<int> result2 = Basa.Solve();


        if(result1.size() == 1 && cntOne <= n - 1 - k && k >= result2.size()) printf("possible\n");
        else printf("impossible\n");

        // sort(result.begin(), result.end());
        // printf("%d\n", (int)result.size());
        // for (int i = 0; i < result.size(); ++i) {
        //     printf("%d ", result[i]);
        // }
        // printf("\n");
    }
    return 0;
}