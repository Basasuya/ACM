#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int N = 2e5 + 5;

vector<int> result;
std::set<pair<int, int> > unExistedMap;
int nextPoint[N];
int prePoint[N];
class List {
   private:
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
    void Solve() {
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
    }
};

int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        unExistedMap.clear();
        result.clear();
        for (int i = 0; i < m; ++i) {
            int from, to;
            scanf("%d %d", &from, &to);
            if (from > to)
                swap(from, to);
            unExistedMap.insert(std::make_pair(from, to));
        }

        List Basa = List(n);
        Basa.Solve();

        sort(result.begin(), result.end());
        printf("%d\n", (int)result.size());
        for (int i = 0; i < result.size(); ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    return 0;
}