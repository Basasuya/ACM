#include <iostream>

void simon(double a, int b);
// void simon(double, int);
int main() {
    simon(2.3, 4);
}

void simon(double x, int y) {
    printf("%lf %d\n", x, y);
}