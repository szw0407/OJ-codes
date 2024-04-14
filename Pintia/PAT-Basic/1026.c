#include<stdio.h>


int main(int argc, char* argv[]){
    int a, b;
    scanf("%d%d", &a, &b);
    int T = b - a;
    int k;
    k = T / 100;
    k = k * 100;
    if (T - k >= 50) {
        T = T / 100 + 1;
    }
    else {
        T = T / 100;
    }
    int h, m, s;
    h = T / 3600;
    T = T - 3600 * h;
    m = T / 60;
    T = T - m * 60;
    s = T;
    printf("%02d:%02d:%02d", h, m, s);


    return 0;
}
