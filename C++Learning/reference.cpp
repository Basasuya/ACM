#include <cstdio>
#include <iostream>

void TestReference1() {
    int a = 1;
    int& b = a;

    std::cout << "a:address->" << &a << std::endl;
    std::cout << "b:address->" << &b << std::endl;

    a = 2;
    b = 3;
    int& c = b;  // 引用一个引用变量，别名的别名
    c = 4;
    printf("%d %d %d\n", a, b, c);
}

void TestReference2() {
    const int a = 5;
    const int& b = a;
    printf("%d %d\n", a, b);
}

int main() {
    TestReference1();
    TestReference2();
}