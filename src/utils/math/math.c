#include <stdio.h>
#include <stdlib.h>

int pow_mod(int x, int n, int mod) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    if(n%2 == 0) {
        return pow_mod(x*x, n/2, mod) % mod;
    }
    return (x % mod)*(pow_mod(x*x, (n-1)/2, mod) % mod) % mod;
}