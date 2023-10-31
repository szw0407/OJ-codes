#include<stdio.h>

int out[200000000];
int in[2000005];
int n;
int i = 0;
int p = 0;

void func(int o, int l) {
    int ind = p - o;
    int p0 = p;
    while (l) {
        out[p++] = out[ind++];
        l--;
        if (ind == p0) {
            ind = p0 - 0;
        }
    }

    return;

}

int main() {
    int a;
    int n;

    int j;
    int l, o;
    p = 0;
    scanf("%d", &n);
    for (i = 0;i < n;i++) {
        scanf("%2x", &in[i]);

    }
    i = 0;
    while (i < n) {
        a = in[i++];
        if (a<128) break;
    }
    while (i<n)
    {
        a = in[i++];
        switch (a%4)
        {
        case 0:
            a = a >> 2;
            if (a < 60) {
                a += 1;
                for (j = 0;j < a;j++) {
                    out[p++] = in[i++];
                }
            }
            else {
                a = a - 60 + 1;
                l = 1;
                for (j = 0;j < a;j++) {
                    l += in[i++] << (8 * j);
                }
                for (j = 0;j < l;j++) {
                    out[p++] = in[i++];
                }
            }
            break;
        case 1:
            l = (a >> 2) % 8;
            l += 4;
            o = a >> 5;
            o = o << 8;
            o += in[i++];
            func(o, l);
            break;
        case 2:
            l = (a >> 2) + 1;
            o = in[i] + (in[i + 1] << 8);
            i += 2;
            func(o, l);
            break;
        default:
            break;
        }
    }
    for (i = 0;i < p;i++) {
        printf("%02x", out[i]);
        if (i % 8 == 7) {
            printf("\n");
        }
    }
    return 0;
}
