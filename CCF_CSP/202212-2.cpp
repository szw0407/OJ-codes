#include<bits/stdc++.h>
#define NUM 105
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i;
    int p[NUM] = {0};
    int t[NUM] = { 0 };
    int tm[NUM] = { 0 };
    int bg[NUM] = { 0 };
    int k[NUM] = { 0 };
    for (i = 1;i <= m;i++) {
        scanf("%d", &p[i]);
    }
    bool print_line_2 = true;
    int tmp;
    int t_aft;
    for (i = 1;i <= m;i++) {
        scanf("%d", &t[i]);
        tm[i] = tm[p[i]] + t[i];
        printf("%d ", tm[p[i]] + 1);
        tmp = i;  // begin with task tmp
        t_aft = t[i];  // time after task starts, to be t[i] if no other task start after this task
        while (tmp > 0) {
            if (k[tmp] < t_aft) {
                // time after the task tmp starts is less than the current time after it
                k[tmp] = t_aft;  // update data
                tmp = p[tmp];  // check the former one
                t_aft += t[tmp];  // to the former one, time after it starts is the current one's time plus its own take time
                if (t_aft > n) {
                    // the time has exceeds
                    print_line_2 = false;
                }
            }
            else
                break;
        }
        

    }
    putchar('\n');
    if (print_line_2) {
        for (i = 1;i <= m;i++) {
            printf("%d ",n-k[i] +1);
        }
        
    }
    return 0;
}