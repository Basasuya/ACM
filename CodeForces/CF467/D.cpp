#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int N = 2e5 + 5;

struct GraphNode {
    int toVertex, nextPoint;
} GraphTable[N];
int headOfVertex[N];
bool visitedVertex[N][2];
int visitedCircle[N];
class Graph {
   private:
    int startVertex_;
    int totEdge_;
    int hasCircle_;
    int hasSuccess_;
    std::vector<int> ansPath;
    bool dfsGraph(int vertex, int step) {
        if (headOfVertex[vertex] == -1) {
            //     printf("%d %d\n", vertex, headOfVertex[vertex]);
            return step & 1;
        }
        for (int i = headOfVertex[vertex]; ~i; i = GraphTable[i].nextPoint) {
            int toVertex = GraphTable[i].toVertex;
            if (!visitedVertex[toVertex][step]) {
                visitedVertex[toVertex][step] = true;
                bool hasSuccess = dfsGraph(toVertex, step ^ 1);
                if (hasSuccess) {
                    ansPath.push_back(toVertex);
                    //   printf("to %d\n", toVertex);
                    return true;
                }
            }
        }
        return false;
    }
    bool judgeCircle(int vertex) {
        visitedCircle[vertex] = -1;
        for (int i = headOfVertex[vertex]; ~i; i = GraphTable[i].nextPoint) {
            int toVertex = GraphTable[i].toVertex;
            if (visitedCircle[toVertex] == 0) {
                bool flag = judgeCircle(toVertex);
                if (flag)
                    return true;
                visitedCircle[toVertex] = 1;
            } else if (visitedCircle[toVertex] == -1)
                return true;
        }
        return false;
    }

   public:
    Graph() {
        ansPath.clear();
        totEdge_ = 0;
        hasSuccess_ = false;
        hasCircle_ = false;
        memset(visitedVertex, 0, sizeof(visitedVertex));
        memset(visitedCircle, 0, sizeof(visitedCircle));
        memset(headOfVertex, -1, sizeof(headOfVertex));
    }
    void setStartVertex(int startVertex) { startVertex_ = startVertex; }
    void addEdge(int fromVertex, int toVertex) {
        //    printf("%d %d\n", fromVertex, toVertex);
        GraphTable[totEdge_].toVertex = toVertex;
        GraphTable[totEdge_].nextPoint = headOfVertex[fromVertex];
        headOfVertex[fromVertex] = totEdge_++;
    }
    void solve() {
        visitedVertex[startVertex_][1] = true;
        hasCircle_ = judgeCircle(startVertex_);
        hasSuccess_ = dfsGraph(startVertex_, 0);

        if (hasSuccess_) {
            ansPath.push_back(startVertex_);
            reverse(ansPath.begin(), ansPath.end());
            printf("Win\n");
            for (int i = 0; i < ansPath.size(); ++i)
                printf("%d ", ansPath[i]);
            printf("\n");
        } else if (hasCircle_)
            printf("Draw\n");
        else
            printf("Lose\n");
    }
};

int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        Graph Basa = Graph();
        for (int i = 1; i <= n; ++i) {
            int numberOfEdge;
            scanf("%d", &numberOfEdge);
            for (int j = 0; j < numberOfEdge; ++j) {
                int toVertex;
                scanf("%d", &toVertex);
                Basa.addEdge(i, toVertex);
            }
        }
        int startVertex;
        scanf("%d", &startVertex);
        Basa.setStartVertex(startVertex);
        Basa.solve();
    }
    return 0;
}