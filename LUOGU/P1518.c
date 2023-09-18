#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


char n[15][15];


int main(int argc, char* argv[]) {
    
    int i, j;
    int x_c, y_c, x_f, y_f;
    int dir_c = 1;
    int dir_f = 1;
    int time = 0;
    int trans_dir(int*, int*, int);
    for (i = 0;i < 10;i++) {

        scanf("%s", &n[i][0]);
        for (j = 0;j < 10;j++) {
            if (n[i][j] == 70) {
                //F
                x_f = j;
                y_f = i;
                break;
            }
            else if (n[i][j] == 67) {
                x_c = j;
                y_c = i;
                break;
            }
            
        }
    }
    while (x_c != x_f || y_c != y_f) {
        time++;
        if (time >= 5000) {
            time = 0;
            break;
        }
        if (trans_dir(&x_c, &y_c, dir_c)) {
            dir_c+=3;
        }

        if (trans_dir(&x_f, &y_f, dir_f)) {
            dir_f+=3;
        }
    }
    
    printf("%d", time);
    return 0;
}

int trans_dir(int *x_pointer, int *y_pointer, int dir) {
    int ret = 0;
    int x = *x_pointer;
    int y = *y_pointer;
    
    switch (dir % 4) {
    case 1:
        if (y==0 || n[y-1][x] == 42) {
            ret = 1;
        }
        else {
            *y_pointer = y - 1;
        }
        break;
    case 2:
        if (x == 0 || n[y][x-1] == 42) {
            ret = 1;
        }
        else {
            *x_pointer = x - 1;
        }
        break;
    case 3:
        if (9 == y || n[y+1][x] == 42) {
            ret = 1;
        }
        else {
            *y_pointer = y + 1;
        }
        break;
    case 0:
        if (9 == x || n[y][x+1] == 42) {
            ret = 1;
        }
        else {
            *x_pointer = x + 1;
        }
        break;
    default:
        break;
    }
    return ret;
}

