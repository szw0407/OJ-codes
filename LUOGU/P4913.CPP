#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

struct tree {
        int l;
        int r;
} p[1000001];

int main(int argc, char* argv[]) {
    
    int i;
    int n;
    scanf("%d", &n);
    for (i = 1;i <= n;i++) {
        scanf("%d%d", &p[i].l, &p[i].r);
    }
    int process(int, int);
    printf("%d",process(1, 0) + 1);
    return 0;
}

int process(int m, int n) {
    int tmp=0;
    if (m != 0) {
        tmp = max(process(p[m].l, n + 1), process(p[m].r, n + 1));
        if (tmp < n) {
            tmp = n;
        }
        
    }
    return tmp;
}