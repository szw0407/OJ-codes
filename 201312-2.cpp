#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a,s,d,f,g,h,j,k,l,w;
    char x;
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",&a,&s,&d,&f,&g,&h,&j,&k,&l,&x);
    if (x =='X'){
        w=10;
    } else{
        w=x-48;
    }
    if (w==(1*a+2*s+3*d+4*f+5*g+6*h+7*j+8*k+9*l)%11){
        printf("Right");

    }
    else{
        x=(1*a+2*s+3*d+4*f+5*g+6*h+7*j+8*k+9*l)%11+48;
        if (x==58){
            x='X';
        }
        printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",a,s,d,f,g,h,j,k,l,x);
    
    }
    return 0;
}