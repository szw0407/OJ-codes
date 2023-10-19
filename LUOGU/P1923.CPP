#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int n;
int main(int argc, char* argv[]) {
    int tot;
    scanf("%d %d", &tot, &n);
    int i;
    int a[tot];
    for (i = 0;i < tot;i++) {
        scanf("%d", &a[i]);
    }
    void bs(int [],int,int);
    bs(a, tot-1,0);
    
    printf("%d", a[n]);
    return 0;
}
void bs(int a[], int k,int f) {
    int l, r;
    int tmp = a[f];
    
    l = f;
    r = k;
    while (l < r)
    {
        while (a[r]>=tmp && l<r){
            r--;
        }
        if (l<r){
            a[l]=a[r];
            l++;
        }
        while (tmp>=a[l] && l<r){
            l++;
        }
        if (l<r){
            a[r]=a[l];
            r--;
        }
        
    }
    a[l] = tmp;
    
    if (f < l) {
        bs(a, l - 1, f);
    }
    
    if (k > l)
        if (l < n+1)
            bs(a, k, l + 1);
        else
            return;
    return;
}