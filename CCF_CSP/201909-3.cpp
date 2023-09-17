#include <stdio.h>
#include <string.h>


int main() {
    int m, n, p, q;
    scanf("%d%d%d%d", &m, &n, &p, &q);
    
    int size = p * q;
    int i, j, k, l;
    int tmp1,tmp2;
    int c[2000][2000][3] = { 0 };
    char s[8] = { 0 };
    gets(s);
    void func(int);
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            gets(s);
        if (strlen(s) == 2) {
            s[3] = s[1];
            s[4] = s[1];
            s[5] = s[1];
            s[6] = s[1];
            s[2] = s[1];
        }
        else if (strlen(s) == 4) {
            s[6] = s[3];
            s[5] = s[3];
            s[4] = s[2];
            s[3] = s[2];
            s[2] = s[1];
        }
        sscanf(s, "#%2x%2x%2x", &c[i][j][0], &c[i][j][1], &c[i][j][2]);
        }
        // cout << i << j << endl;
        // printf("%d %d %d\n", c[i][j][0], c[i][j][1], c[i][j][2]);
    }
    int R, G, B;
    int r = 0;
    int g = 0;
    int b = 0;
    for (int i = 0; i < n; i += q) {
        for (int j = 0; j < m; j += p) {
            R = G = B = 0;
            for (k = i;k < i + q;k++) {
                for (l = j;l < j + p;l++) {
                    // cout << l << k << endl;
                    // cout << c[k][l][0] << c[k][l][1] << c[k][l][2] << endl;
                    R += c[k][l][0];
                    G += c[k][l][1];
                    B += c[k][l][2];
                }
            }
            R /= size;
            G /= size;
            B /= size;
            if(!(R == r && G == g && B == b)){ // different from the former color
                if (!R && !G && !B) {  // is black
                    // reset color
                    printf("\\x1B\\x5B\\x30\\x6D");
                }
                else {
                    // change color
                    printf("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B");
                    func(R);
                    printf("\\x3B");
                    func(G);
                    printf("\\x3B");
                    func(B);
                    printf("\\x6D");
                }
            }
            r = R, g = G, b = B;
            printf("\\x20");
        }
        if (r || g || b) {
            printf("\\x1B\\x5B\\x30\\x6D");
        }
        printf("\\x0A");
        r = 0;
        g = 0;
        b = 0;
    }
    return 0;
}

void func(int num) {
    int tmp1, tmp2,tmp3;
    if (num < 10) {
        printf("\\x%02X", num+48);
    }
    else if (num < 100) {
        tmp1 = num / 10;
        tmp2 = num - 10*tmp1;
        printf("\\x%02X\\x%02X", tmp1+48, tmp2+48);
    }
    else {
        tmp1 = num / 100;
        tmp2 = (num - 100*tmp1) / 10;
        tmp3 = num - 100 * tmp1 - 10 * tmp2;
        printf("\\x%02X\\x%02X\\x%02X", tmp1+48, tmp2+48,tmp3+48);
    }
    return;
}