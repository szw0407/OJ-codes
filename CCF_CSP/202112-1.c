#include<stdio.h>

int main() {
    int n, N;
    scanf("%d %d",&n, &N);
    int i;
    int ind = 0;
    int tot = 0;
    int a[205] = { 0 };
    int d[10000000] = { 0 };
    // for a certain list of nums: [x0, x1, x2, ..., xn] (len === n+1)
    // we can create another list: [x1-x0, x2-x1, ..., xn-x(n-1)] (len === n), 
    //        also referred to as: [a1, a2, ..., an]
    // then we create a list [first_num, first_num + a1, first_num + a1 + a2, ..., first_num + sum(a1:an) ]
    // which can be just equal to [x0, x1, x2, ... , xn]
    // if the required array is [0, 1, 2, 3, 3], simply we can record it as [1, 1, 1, 0]

    for (i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        d[a[i]]=1;
    }
    for (i = 1;i < N;i++) {
        d[i] += d[i - 1];
        tot += d[i];
    }
    // for (i=0;i<N;i++) {
    //     while (a[ind]<=i) {
    //         ind ++;
    //         if (ind == n+1){
    //             tot += n*(N-i);
    //             printf("%d\n",tot);
    //             return 0;
    //         }
    //     }
    //     tot += ind -1;
    // }
    printf("%d\n", tot);

    return 0;
}