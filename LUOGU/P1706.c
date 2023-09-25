#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int a[13] = { 0 };
int out[10] = { 0 };

int main(int argc, char* argv[]) {
    int n;
    int i;
    scanf("%d", &n);

    void operate(int, int);
    
    operate(n,0);

    return 0;
}

void operate(int n, int num) {
    int i;
    if (num == n) {
        for (i = 0;i < n;i++) {
            printf("%5d", out[i]);
        }
        printf("\n");
    }
    else {
        for (i = 1;i < n + 1;i++) {
            if (a[i] == 0) {
                a[i] = 1;
                out[num] = i;
                operate(n, num + 1);
                a[i] = 0;
            }
        }
    }
    
    return;
}