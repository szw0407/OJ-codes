#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

struct person {
        int time = 0;
        int index = 0;
    } p[1002];
    

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    __int128_t avg=0.0;
    int tmp;
    bool cmp(person, person);

    int i;
    for (i = 0;i < n;i++) {
        scanf("%d", &p[i].time);
        p[i].index = i+1;
    }
    sort(&p[0], &p[n], cmp);
    for (i = 0;i < n;i++) {
        printf("%d ", p[i].index);
        if (i >= 1) {
            tmp = tmp + p[i - 1].time;
            avg += tmp;
        }
    }
    // avg /= n ;
    printf("\n%.2lf", (double) avg/n);
    return 0;
}


bool cmp(person a, person b) {
    return a.time < b.time;
}