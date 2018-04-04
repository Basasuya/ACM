#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
const int maxLength = 2005;

char s[maxLength], t[maxLength];
int letterOfS[30];
int letterOfT[30];
std::vector<int> result;
void shift(char* seqence, int location) {
    std::string tt = seqence;
    tt = tt.substr(location) + tt.substr(0, location);
    std::reverse(tt.begin(), tt.begin() + tt.length() - location);
    for (int i = 0, length = tt.length(); i < length; ++i) {
        seqence[i] = tt[i];
    }
    //   seqence[tt.length()] = 0;

    result.push_back(tt.length() - location);
    //   printf("%s\n", seqence);
}
void solveChange(int length) {
    int okLength = 0;
    for (int i = 0; i < length; ++i) {
        char targetLetter = t[i];
        int LocationOftargetInS;
        for (int j = 0; j < length - i; ++j) {
            if (s[j] == targetLetter) {
                LocationOftargetInS = j;
                break;
            }
        }
        //   printf("%d\n", LocationOftargetInS);
        shift(s, LocationOftargetInS + 1);
        shift(s, length - 1);
        shift(s, 0);
        //    printf("\n");
    }
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        result.clear();
        memset(letterOfS, 0, sizeof(letterOfS));
        memset(letterOfT, 0, sizeof(letterOfT));

        scanf("%s %s", s, t);
        for (int i = 0; i < n; ++i) {
            letterOfS[s[i] - 'a']++;
        }
        for (int i = 0; i < n; ++i) {
            letterOfT[t[i] - 'a']++;
        }
        bool canChange = true;
        for (int i = 0; i < 26 && canChange; ++i) {
            if (letterOfS[i] != letterOfT[i]) {
                canChange = false;
            }
        }

        if (canChange) {
            solveChange(n);
            printf("%d\n", (int)result.size());
            for (int i = 0; i < result.size(); ++i) {
                printf("%d ", result[i]);
            }
            printf("\n");
        } else
            printf("-1\n");
    }
    return 0;
}
