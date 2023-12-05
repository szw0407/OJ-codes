#include<stdio.h>
#include<math.h>
#define UP 1
#define DOWN -1
#define PI acos(-1)

double a(int u) {
    if (u != 0) {
        return 1.0;
    }
    else {
        return sqrt(0.5);
    }
}

int main() {
    int Q[8][8];
    int d[8][8] = { 0 };
    double e[8][8] = { 0 };
    int f[8][8];
    int i, j, k;
    int u, v;
    for (i = 0;i < 8;i++) {
        for (j = 0;j < 8;j++) {
            scanf("%d", &Q[i][j]);
        }
    }
    int n;
    scanf("%d", &n);
    int T;
    scanf("%d", &T);
    i = 0;
    j = 0;
    int t = UP;
    for (k = 0;k < n;k++) {
        scanf("%d", &d[i][j]);
        j += t;
        i -= t;
        if (i < 0 && j < 8) {
            i = 0;
            t = DOWN;
        }
        else if (j < 0 && i < 8) {
            j = 0;
            t = UP;
        }
        else if (j >= 8 || i >= 8) {
            if (t == DOWN) {
                i -= 1;
                j += 2;
                t = UP;
            }
            else {
                i += 2;
                j -= 1;
                t = DOWN;
            }
        }
    }
    for (i = 0;i < 8;i++) {
        for (j = 0;j < 8;j++) {
            if (T == 0) {
                printf("%d ", d[i][j]);
            }
            else {
                d[i][j] *= Q[i][j];
                if (T == 1) {
                    printf("%d ", d[i][j]);
                }
            }
        }
        if (T == 0 || T == 1) {
            putchar('\n');
        }
    }
    if (T) {
        for (i = 0;i < 8;i++) {
            for (j = 0;j < 8;j++) {
                for (u = 0;u < 8;u++) {
                    for (v = 0;v < 8;v++) {
                        e[i][j] += 0.25 * a(u) * a(v) * d[u][v] * cos(PI / 8 * (i + 0.5) * u) * cos(PI / 8 * (j + 0.5) * v);
                    }
                }
            }
        }
    }
    if (T == 2) {
        for (i = 0;i < 8;i++) {
            for (j = 0;j < 8;j++) {
                f[i][j] = round(128 + e[i][j]);
                if (f[i][j] < 0) f[i][j] = 0;
                else if (f[i][j] > 255) f[i][j] = 255;
                printf("%d ", f[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}