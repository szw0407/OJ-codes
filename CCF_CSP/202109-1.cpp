#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int n;
    scanf("%d",&n);
    int b[100];
    int a1[100];
    int a2[100];
    scanf("%d",&b[0]);
    a1[0]=b[0];
    a2[0]=b[0];
    int max=a2[0];
    int min = a1[0];
    int i;
    for (i = 1;i < n;i++) {
        scanf("%d",&b[i]);
        if (b[i]==b[i-1]){
            a1[i]=0;
        }
        else{
            a1[i]=b[i];
            min+=a1[i];
        }
        a2[i]=b[i];
        max+=a2[i];
    }
    printf("%d\n%d",max,min);
    return 0;
}
