#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;




// /*
// int isPrime[N];
// int primes[N];
// int mu[N];
// int num;
// void sieve() {
//     fill(isPrime, isPrime + N, 1);
//     mu[1] = 1, num = 0;
//     for (int i = 2; i < N; ++i) {
//         if (isPrime[i]) primes[num++] = i, mu[i] = -1;
//         static int d;
//         for (int j = 0; j < num && (d = i * primes[j]) < N; ++j) {
//             isPrime[d] = false;
//             if (i % primes[j] == 0) {
//                 mu[d] = 0;
//                 break;
//             } else mu[d] = -mu[i];
//         }
//     }
// }*/



int isPrime[N]; 
int Prime[N];
int primeTot;
int main() {
    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }

    for(int i = 1; i <= primeTot; ++i) {
        if(1ll * Prime[i] * Prime[i] > n) break;
        if(n % Prime[i] == 0) {
            while(n % Prime[i] == 0) {
                n /= Prime[i];
            }
            st.insert(Prime[i]);
        }
    }
    if(n != 1) {
        st.insert(n);
    }
}