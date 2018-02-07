#include <cmath>
#include <cstdio>
#include <iostream>
const int N = 3e5 + 5;
const int M = 1e6 + 5;

int n, m;
int a[N];
long long sumOfSegment[N << 2];
int maxOfSegment[N << 2];
class SegmentTree {
   private:
    int numberOfPoints;
    int functionD(int x) {
        int ans = 0;
        int sqx = (int)sqrt(x);
        for (int i = 1; i <= sqx; ++i) {
            if (x % i == 0)
                ans += 2;
        }
        if (sqx * sqx == x)
            ans--;
        return ans;
    }
    void BuildSegmentTree(int leftPos, int rightPos, int rootIndex) {
        if (leftPos == rightPos) {
            sumOfSegment[rootIndex] = a[leftPos];
            maxOfSegment[rootIndex] = a[leftPos];
            return;
        }
        int middlePos = (leftPos + rightPos) / 2;
        BuildSegmentTree(leftPos, middlePos, rootIndex << 1);
        BuildSegmentTree(middlePos + 1, rightPos, rootIndex << 1 | 1);
        treeUpdateUp(rootIndex);
    }

   public:
    SegmentTree(int n) : numberOfPoints(n) { BuildSegmentTree(1, numberOfPoints, 1); }
    void treeUpdateUp(int rootIndex) {
        sumOfSegment[rootIndex] = sumOfSegment[rootIndex << 1] + sumOfSegment[rootIndex << 1 | 1];
        maxOfSegment[rootIndex] = std::max(maxOfSegment[rootIndex << 1], maxOfSegment[rootIndex << 1 | 1]);
    }

    void Update(int leftRange, int rightRange, int leftPos, int rightPos, int rootIndex) {
        if (maxOfSegment[rootIndex] <= 2)
            return;
        if (leftPos == rightPos) {
            sumOfSegment[rootIndex] = maxOfSegment[rootIndex] = functionD(sumOfSegment[rootIndex]);
            return;
        }
        int middlePos = (leftPos + rightPos) / 2;
        if (leftRange <= middlePos)
            Update(leftRange, rightRange, leftPos, middlePos, rootIndex << 1);
        if (rightRange > middlePos)
            Update(leftRange, rightRange, middlePos + 1, rightPos, rootIndex << 1 | 1);
        treeUpdateUp(rootIndex);
    }
    long long Sum(int rightRange, int leftPos, int rightPos, int rootIndex) {
        if (rightRange == 0)
            return 0;
        if (rightPos <= rightRange)
            return sumOfSegment[rootIndex];
        int middlePos = (leftPos + rightPos) / 2;
        long long ans = Sum(rightRange, leftPos, middlePos, rootIndex << 1);
        if (rightRange > middlePos)
            ans += Sum(rightRange, middlePos + 1, rightPos, rootIndex << 1 | 1);
        return ans;
    }
};

int main() {
    //   printf("%d %d\n", functionD(1), functionD(2));
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        SegmentTree Basa = SegmentTree(n);
        //    printf("%lld\n", sumOfSegment[1]);
        for (int i = 1; i <= m; ++i) {
            int t, l, r;
            scanf("%d %d %d", &t, &l, &r);
            if (t == 1)
                Basa.Update(l, r, 1, n, 1);
            else
                printf("%lld\n", Basa.Sum(r, 1, n, 1) - Basa.Sum(l - 1, 1, n, 1));
        }
    }
    return 0;
}
