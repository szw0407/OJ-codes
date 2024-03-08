#include<bits/stdc++.h>

#define MAX_CNT 2002

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j, k;
    int id;
    int tmp;
    int w[MAX_CNT], p[MAX_CNT], w_bk[MAX_CNT];
    int sum_w[MAX_CNT] = { 0 };
    int rem;
    std::vector<int> c[MAX_CNT], f[MAX_CNT];
    for (i = 1;i <= n;i++) {
        scanf("%d", &w_bk[i]);
    }
    for (i = 2;i <= n;i++) {
        scanf("%d", &p[i]);
    }
    int tot;
    int min_w_del, min_j;
    bool flag, flag2;
    for (i = 0;i < m;++i) {
        scanf("%d", &id);
        rem = n;  // everything remains
        for (j = 1;j <= n;j++) {
            w[j] = w_bk[j];
        }
        while (rem > 1) {
            tot = 0;
            for (j = 1;j <= n;j++) {
                sum_w[j] = 0;
            }
            for (j = 1;j <= n;j++) {
                if (w[j] == 0) continue;
                tmp = j;
                tot += w[j];
                while (1) {
                    sum_w[tmp] += w[j];
                    if (tmp != 1) {
                        tmp = p[tmp];
                    }
                    else break;
                }
            }
            min_w_del = tot;
            for (j = 2;j <= n;j++) {
                if (sum_w[j] == 0) continue;
                if (min_w_del > abs(tot - 2 * sum_w[j])) {
                    min_j = j;
                    min_w_del = abs(tot - 2 * sum_w[j]);
                }
            }
            printf("%d ", min_j);
            // check if id is min_j
            tmp = id;
            flag = false;
            do {
                flag = (tmp == min_j);
                if (flag) {
                    break;
                }
                tmp = p[tmp];
            } while (tmp != 1);

            for (j = 1;j <= n;j++) {
                if (w[j] == 0) continue;
                tmp = j;
                flag2 = flag;
                while (tmp != 1) {
                    if (tmp == min_j) {
                        flag2 = !flag;
                        break; //find
                    }
                    tmp = p[tmp];
                }
                if (flag2) {
                    w[j] = 0;
                    rem--;
                }
            }
        }
        putchar('\n');
    }

    return 0;
}