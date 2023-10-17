#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);
    int i, j;
    double num[1000];
    double sum = 0.0;
    for (i = 0;i < n;i++) {
        scanf("%lf", &num[i]);
        sum += num[i];
    }
    double avg = sum / n;
    
    sum = 0.0;
    for (i = 0;i < n;i++) {
        sum+=(num[i] - avg)* (num[i] - avg);
    }
    
    double d = sum / n;
    for (i = 0;i < n;i++) {
        printf("%lf\n", (num[i] - avg) / sqrt(d));
    }
    return 0;
}