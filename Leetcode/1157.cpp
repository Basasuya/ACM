#include <bits/stdc++.h>
using namespace std;

struct segment {
    int value, count;

    segment(int v = 0, int c = 0) : value(v), count(c) {}

    void join(const segment &other) {
        if (value == other.value) {
            count += other.count;
            return;
        }

        if (count >= other.count) {
            count -= other.count;
        } else {
            value = other.value;
            count = other.count - count;
        }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;

    seg_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--) {
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
            printf("%d %d %d\n", position, tree[position].value, tree[position].count );
        }
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        printf("%d %d\n", start, end);
        if (a <= start && end <= b) {
            
            range_op(position, end - start);
            return;
        }

        if (position >= tree_n)
            return;

        int mid = (start + end) / 2;
        if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }
};


class MajorityChecker {
private:
    seg_tree tree;
    map<int, vector<int>> locations;

public:
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        vector<segment> initial;
        locations.clear();

        for (int i = 0; i < n; i++) {
            initial.emplace_back(arr[i], 1);
            locations[arr[i]].push_back(i);
        }

        tree.init(n);
        tree.build(initial);
    }

    int count_freq(int x, int left, int right) {
        return lower_bound(locations[x].begin(), locations[x].end(), right) - (
            lower_bound(locations[x].begin(), locations[x].end(), left));
    }

    int query(int left, int right, int threshold) {
        right++;
        segment result = tree.query(left, right);

        // if (count_freq(result.value, left, right) >= threshold)
            return result.value;

        // return -1;
    }
};

int main() {
    vector<int> tmp = {1,1,1,1,3,3,3,4,2,2,2,2,3,3,3,4};
    
    MajorityChecker* majorityChecker = new MajorityChecker(tmp);
    printf("%d\n", majorityChecker->query(0,15,4));
    // majorityChecker->query(0,5,4); // returns 1
    // majorityChecker->query(0,3,3); // returns -1
    // majorityChecker->query(2,3,2); // returns 2

}