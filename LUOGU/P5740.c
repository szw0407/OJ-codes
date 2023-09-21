#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
    char max_student_name[10] = { 0 };
    char name[10] = { 0 };
    int n;
    int a, b, c;
    int sum = 0;
    int maxa = 0;
    int maxb = 0;
    int maxc = 0;
    
    scanf("%d", &n);
    int i, j;
    scanf("%s %d %d %d", max_student_name, &maxa, &maxb, &maxc);
    int maxsum = maxa + maxb + maxc;
    // Here a comment: The problem has a set in which all members' all scores are zero
    // So the max_student_name should be set here, otherwise no student name is given!
    for (i = 1;i < n;++i) {
        scanf("%s %d %d %d", name, &a, &b, &c);
        sum = a + b + c;
        if (sum > maxsum) {
            for (j = 0;j < 10;j++) {
                max_student_name[j] = name[j];
            }
            maxsum = sum;
            maxa = a;
            maxb = b;
            maxc = c;
        }
    }
    printf("%s %d %d %d", max_student_name, maxa, maxb, maxc);
    return 0;
}
