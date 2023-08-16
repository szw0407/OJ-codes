#include<stdio.h>
#include<string.h>
int main() {
    char s[102];
    gets(s);
    for (int i = 0;i < strlen(s);i++) {
        if (s[i] >= 0x61 && s[i] <= 0x7A) {
            s[i] -= 0x20;
        }
    }
    puts(s);
    return 0;
}