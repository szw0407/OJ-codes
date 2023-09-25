#include<iostream>
#include<cstdio>

int n, m;
int hx, hy;
unsigned long long step_record[30][30] = { 0 };

int main(int argc, char* argv[]) {

    scanf("%d%d%d%d", &n, &m, &hx, &hy);
    unsigned long long step(int, int);
    step_record[0][0] = 1;
    std::cout << step(n, m) << std::endl;
    return 0;
}

unsigned long long step(int x, int y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    else if ((x == hx-1 || x == hx+1) && (y == hy-2 || y == hy+2) || (x == hx-2 || x == hx+2) && (y == hy-1 || y == hy+1)||(x==hx&&y==hy)) {
        return 0;
    }
    else if (x==0 && y==0)
    {
        return 1;
    }
    else {
        if (step_record[x][y] == 0) {
            step_record[x][y] = step(x - 1, y) + step(x, y - 1);
        }
        return step_record[x][y];
    }
}