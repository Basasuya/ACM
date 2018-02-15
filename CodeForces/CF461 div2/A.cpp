#include <cstdio>

bool Judege(int copyToy, int originToy) {
    int actionCopy = copyToy - originToy + 1;
    if ((originToy == 1 && actionCopy == 0) || (originToy > 1 && actionCopy >= 0 && actionCopy % 2 == 0))
        return true;
    else
        return false;
}

int main() {
    int x, y;
    while (~scanf("%d %d", &x, &y)) {
        printf("%s\n", Judege(x, y) ? "Yes" : "No");
    }
    return 0;
}