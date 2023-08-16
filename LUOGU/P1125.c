#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
    char s[102];
    gets(s);
    int num[256] = { 0 };
    int i;
    int max = 0;
    int min = 102;
    int res;
    for (i = 0; i < strlen(s);i++) {
        num[s[i]]++;
    }
    for (i = 0;i < 256;i++) {
        if (num[i] > max) {
            max = num[i];
        }
        if (num[i] && num[i] < min) {
            min = num[i];
        }
    }
    res = max - min;
    for (i = 2;i <= sqrt(res);i++) {
        if (res % i == 0) {
            res = 0;
            break;
        }
    }
    if (res == 1) {
        res = 0;
    }
    if (res) {
        printf("Lucky Word\n%d", res);
    }
    else {
        printf("No Answer\n0");
        
    }
    return 0;
}