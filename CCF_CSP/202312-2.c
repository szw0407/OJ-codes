#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int is_prime(int num) {
    int i;
    for (i = 2;i <= sqrt(num);i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char* argv[]) {
    int q;
    scanf("%d", &q);
    long long int n, k;
    long long int i, j;
    int t;
    long long int num;
    long long int tmp;
    for (i = 0;i < q;++i) {
        scanf("%lld%lld", &n, &k);
        num = 1;
        for (j = 2;j <= sqrt(n);j++) {
            if (is_prime(j)) {
                t = 0;
                tmp = 1;
                while (n % j == 0)
                {
                    n /= j;
                    t++;
                    tmp *= j;
                }
                if (t >= k) {
                    // printf("%d  ", tmp);
                    num *= tmp;
                }

            }
        }
        printf("%lld\n", num);
    }
    return 0;
} 