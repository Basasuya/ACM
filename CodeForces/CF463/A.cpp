#include <cstdio>
#include <cstring>

const int maxLength = 1e3 + 5;

char palindromic[maxLength];

int main() {
    while (~scanf("%s", palindromic)) {
        printf("%s", palindromic);
        int len = strlen(palindromic);
        for (int i = len - 1; i >= 0; --i) {
            printf("%c", palindromic[i]);
        }
        printf("\n");
    }
    return 0;
}