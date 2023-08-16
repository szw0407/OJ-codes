#include<stdio.h>
#include<string.h>
int main() {
    int n;
    scanf("%d", &n);
    int i;
    char s[100] = { 0 };
    int a, b;
    char o;
    int res;
    char out[1000000] = { 0 };
    char tmp[1000] = { 0 };
    getchar();getchar();
    int j;
    for (i = 0;i < n;i++) {
        res = strlen(s);
        for (j = 0;j < res;j++) {
            s[j] = 0;
        }
        gets(s);

        if (s[0] != 0x61 && s[0] != 0x63 && s[0] != 0x62) {
            sscanf(s, "%d%d", &a, &b);
        }
        else {
            sscanf(s, "%c %d %d", &o, &a, &b);
        }
        switch (o) {
        case 0x61:
            sprintf(tmp, "%d+%d=%d", a, b, a + b);
            break;

        case 0x62:
            sprintf(tmp, "%d-%d=%d", a, b, a - b);
            break;
        case 0x63:
            sprintf(tmp, "%d*%d=%d", a, b, a * b);
            break;

        }
        res = strlen(tmp);
        strcat(out, tmp);
        res = strlen(tmp);
        for (j = 0;j < res;j++) {
            tmp[j] = 0;
        }
        sprintf(tmp, "\n%d\n", res);
        strcat(out, tmp);

    }
    printf("%s", out);
    return 0;
}