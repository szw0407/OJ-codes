#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

struct person
{
    int id;
    int score;
};

bool cmp(person a, person b) {
    if (a.score < b.score) {
        return false;
    }
    else if (a.score == b.score) {
        return a.id < b.id;
    }
    else {
        return true;
    }
}

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    int num;
    m = floor(m * 1.500);

    int k[10000], s[10000];
    int i,j;
    person p[10000];
    for (i = 0;i < n;i++) {
        scanf("%d %d", &p[i].id, &p[i].score);
    }
    sort(p, p+n, cmp);
    i = 0;
    while (p[i].score >= p[m-1].score) {
        i++;
    }
    printf("%d %d\n", p[i-1].score, i);
    for (j = 0;j < i;j++) {
        printf("%d %d\n", p[j].id, p[j].score);
    }
    return 0;
}
