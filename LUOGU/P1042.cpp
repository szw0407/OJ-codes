#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    char c[26 * 2600];
    int i = 0;
    int a[2][6000] = { 0 };
    int b[2][6000] = { 0 };
    int j, k;
    j = 0;
    k = 0;
    while (1) {
        c[i] = getchar();
        if (c[i] == 'E') {
            break;
        }
        if (c[i] == '\n')
            i--;
        else if (c[i] == 'W') {
            a[0][j]++;
            b[0][k]++;
        }
        else if (c[i] == 'L') {
            a[1][j]++;
            b[1][k]++;
        }
        if (a[0][j] >= 11 || a[1][j] >= 11) {
            if (a[0][j] - a[1][j] > 1 || a[1][j] - a[0][j] > 1)
                j++;
        }
        if (b[0][k] >= 21 || b[1][k] >= 21) {
            if (b[0][k] - b[1][k] > 1 || b[1][k] - b[0][k] > 1)
                k++;
        }
        i++;
    }
    for (i = 0;i <= j;i++) {

        printf("%d:%d\n", a[0][i], a[1][i]);
    }
    printf("\n");
    for (i = 0;i <= k;i++) {

        printf("%d:%d\n", b[0][i], b[1][i]);
    }

    return 0;
}
