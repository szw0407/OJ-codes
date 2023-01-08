#include<stdio.h>

int main() {
    int s, t, w;
    scanf("%d %d %d\r\n", &s, &t, &w);
    char a[28] = { 0 };
    int i;
    for (i = 1;i <= w;i++) {
        scanf("%c", &a[i]);

    }
    s += 96;
    t += 96;
    int pr(char[], int, int);
    int st;
    int j;
    for (j = 0;j < 5;j++) {
        st = pr(a, w, t);
        if (st == 0) {
            for (i = 1;i <= w;i++)
                printf("%c", a[i]);
            if (j!=4) printf("\n");
        }
    }
    return 0;
}

int pr(char a[], int wi, int t) {
    a[wi]++;
    int tmp = 0;
    if (a[wi] > t) {
        if (wi > 1) {
            tmp = pr(a, wi - 1, t - 1);
            a[wi] = a[wi - 1] + 1;
        }
        else
            return 1;
    }
    return tmp;
}