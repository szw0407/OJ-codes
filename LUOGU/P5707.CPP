#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int s, v;
    int i = 0;
    int h = 8;
    int m = 0;
    scanf("%d%d", &s, &v);
    while (s>0)
    {
        i++;
        s -= v;
    }
    i += 10;
    while (i>=60)
    {
        i -= 60;
        h--;
    }
    if (i > 0) {
        m = 60;
        h--;
        while (i > 0) {
            i--;
            m--;
        }
    }
    while (h < 0) {
        h += 24;
    }
    if (h < 10) {
        if (m > 9)
            printf("0%d:%d", h, m);
        else {
            printf("0%d:0%d", h, m);
        }
    }
    else {
        if (m > 9)
            printf("%d:%d", h, m);
        else {
            printf("%d:0%d", h, m);
        }
    }
    return 0;
}
