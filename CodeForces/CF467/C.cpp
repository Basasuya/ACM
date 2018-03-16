#include <cstdio>
#include <cstring>

const int N = 1e5 + 5;

double needTime(long long turnOffTime, long long goKichenTime, long long cookTime) {
    cookTime *= 2;

    // double the cookTime so turnOn as 2 timeunit per second turn off as 1 timeunit per second
    if (turnOffTime < goKichenTime || turnOffTime % goKichenTime) {
        goKichenTime = turnOffTime > goKichenTime ? (goKichenTime - turnOffTime % goKichenTime + turnOffTime) : goKichenTime;

        long long UnitOfCook = turnOffTime + goKichenTime;
        long long cookTimeReminder = cookTime % UnitOfCook;
        long long cookTimeInteger = cookTime - cookTimeReminder;
        double needTimeResult = goKichenTime * (cookTime / UnitOfCook);
        //    printf("%lld %lld %lld %lld\n", UnitOfCook, cookTimeReminder, cookTimeInteger, goKichenTime);
        if (cookTimeReminder < 2 * turnOffTime)
            return needTimeResult + cookTimeReminder * 1.0 / 2;
        else
            return needTimeResult + turnOffTime + (cookTimeReminder - 2 * turnOffTime);
    } else
        return cookTime / 2;
}
int main() {
    long long k, d, t;
    while (~scanf("%lld %lld %lld", &k, &d, &t)) {
        printf("%.9f\n", needTime(k, d, t));
    }
    return 0;
}