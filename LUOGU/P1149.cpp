#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;


int num[10] = { 6,2,5,5,4,5,6,3,7,6 };


int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int i, j, k;
    int res = 0;
    int count(int);
    for (i = 0;i < 1000;i++) {
        for (j = 0; j < 1000;j++) {
            if (count(i) + count(j) + count(i + j) == n - 4) {
                res++;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}


int count(int x) {
    if (x < 10) {
        return num[x];
    }
    else {
        return count(x / 10) + num[x - x / 10 * 10];
    }

}