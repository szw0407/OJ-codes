#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    char A[15] = { 48 };
    char B[15] = { 48 };
    int da, db;
    scanf("%s %c %s %c", A, &da, B, &db);
    int i;
    long long a, b;
    a = 0;
    b = 0;
    for (i = 0;i < strlen(A);i++) {
        if (A[i] == da) {
            a = a * 10 + (da - 48);
        }

    }
    for (i = 0;i < strlen(B);i++) {
        if (B[i] == db) {
            b = b * 10 + (db - 48);
        }
    }
    printf("%d", a + b);
    return 0;
}