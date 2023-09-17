#include<stdio.h>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]){
    int n;;
    scanf("%d", &n);
    int a[100000];
    double md;
    int i;
    for (i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    if (n % 2 != 0)
        printf("%d %d %d\n", a[n - 1], a[(int)n / 2], a[0]);
    else
        if ((a[(int)n / 2] + a[(int)n / 2 -1]) % 2 == 0)

            printf("%d %d %d\n", a[n - 1], (a[(int)n / 2] + a[(int)n / 2 - 1]) / 2, a[0]);
        else {
            md = ((double)a[n / 2] + (double)a[n / 2 - 1]) / 2;
            printf("%d %.1f %d\n", a[n - 1], md, a[0]);
        }

    return 0;
}