#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int m, n;
    scanf("%d %d", &m, &n);
    long long int max = n > m ? n : m;
    long long int min = m > n ? n : m;
    long long int i,j,k;
    long long suma = 0;
    long long sumb = 0;
    for (i = 0;i < min;i++) {
        suma += (max - i) * (min - i);
        for (j = 0;j < max;j++) {
            if (j == i) {
                continue;
            }
            sumb += (min - i) * (max - j);
        }
    }
    cout << suma << ' ' << sumb << endl;
    
    return 0;
}