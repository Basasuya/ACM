#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        if (a % 2 && b % 2) {
            printf("Yes\n");
        } else
            printf("No\n");
    }
    return 0;
}