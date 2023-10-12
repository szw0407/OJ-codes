#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;


int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    int i;
    int a[500003] = {0};
    int n[10002] = {0};
    scanf("%d", &a[0]);
    for (i = 1;i < N;i++) {
        scanf("%d", &a[i]);
        if (a[i] < a[i - 1]) {
            n[a[i]+1]++;
            n[a[i - 1]+1]--;
        }
    }
    if (a[i] < a[i - 1]) {
        n[a[i]+1]++;
        n[a[i - 1] + 1]--;
    }
    int maxres = 0;
    int res = 0;
    for (i = 0;i < 10002;i++) {
        res += n[i];
        maxres = max(res, maxres);
    }
    printf("%d", maxres);
    return 0;
}