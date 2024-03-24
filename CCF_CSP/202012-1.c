#include<stdio.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int i;
    int score = 0;
    int s, w;
    for (i = 0;i < n;i++) {
        scanf("%d%d", &s, &w);
        score += s * w;
    }
    if (score < 0) printf("0\n");
    else printf("%d\n", score);
    return 0;
}