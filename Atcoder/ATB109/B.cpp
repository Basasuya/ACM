#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    map<string, int> mp;
    while (~scanf("%d", &n)) {
        char seq[15];
        mp.clear();
        bool flag = true;
        char tag;
        for (int i = 0; i < n; ++i) {
            scanf("%s", seq);

            if (mp.find(seq) != mp.end() || (i && tag != seq[0])) flag = false;
            mp[seq]++;
            tag = seq[strlen(seq) - 1];
        }

        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}