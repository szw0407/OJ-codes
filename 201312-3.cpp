#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int n;
    int a[1002] = {0};
    int s[1002] = {0};
    int l = 1;
    int r;
    scanf("%d", &n);
    int i;
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int j;
    for (i = 0;i < n;i++) {
        j = i;
        r = i;
        while (j<n-1 && a[j + 1] >= a[i]) {
            r++;
            j++;
        }
        j = i;
        l = i;
        while (j > 0 && a[j - 1] >= a[i]) {
            l--;
            j--;
        }
        s[i] = a[i] * (r-l+1);
    }
    printf("%d", *max_element(s,s+n));
    return 0;
}
