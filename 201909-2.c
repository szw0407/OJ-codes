#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);
    int i,j;
    int m;
    int ai[1002] = {0};
    int number = 0;
    int total = 0;
    int d[1002] = { 0 };
    int D = 0;
    int E = 0;
    
    for (i = 1;i <= n;i++) {
        scanf("%d", &m);
        number = 0;
        for (j = 1;j <= m;j++) {
            scanf("%d", &ai[j]);
            if (ai[j] <= 0) {
                number += ai[j];
            }
            else {
                if (number == ai[j]) {
                    // Nothing happens
                    ;
                }
                else {
                    number = ai[j];
                    if (j!=1)
                    d[i] = 1;
                }
            }
        }
        if (i>=3 && d[i - 1] + d[i] + d[i - 2] == 3) {
            E++;
        }
        D+=d[i];
        total += number;
    }
    //1 2 3
    //...
    //998 999 1000
    // OK
    //999 1000 1
    i--;
    if (d[i] + d[i - 1] + d[1] == 3) {
        E++;
    }
    // 1000 1 2
    if (d[i] + d[1] + d[2] == 3) {
        E++;
    }
    printf("%d %d %d\n", total, D, E);
    return 0;
}
