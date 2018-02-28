#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
const int N = 1e5 + 5;
char s[N];
int function[N];
int getFunction(char* s) {
    int sCount = 0;
    int sumOfFunction = 0;
    for (int i = 0, len = strlen(s); i < len; ++i) {
        if (s[i] == 's')
            sCount = 0;
        else
            sumOfFunction += sCount;
    }
    return sumOfFunction;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            function[i] = getFunction(s);
        }
        sort(f)
    }
    return 0;
}