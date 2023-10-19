#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a,b,c,d;
    char x,y,z;
    // stack<char> s;
    bool cmp(char, char);
    int calc(int, char, int);
    for (i=0;i<n;i++){
        scanf("%1d%c%1d%c%1d%c%1d",&a,&x,&b,&y,&c,&z,&d);
        // +:43, -:45, x:120, /:47
        if (cmp(x,y)){
            if (cmp(y,z)) {
                c=calc(c,z,d);
            }
            else {
                b=calc(b,y,c);
                y=z;
                c=d;
            }
            
        }
        else {
            a=calc(a,x,b);
            b=c;
            c=d;
            x=y;
            y=z;
        }
        if (cmp(x,y)) {
            b=calc(b,y,c);
        }
        else {
            a=calc(a,x,b);
            b=c;
            x=y;
        }
        a=calc(a,x,b);
        if (a==24) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}

bool cmp(char a, char b) {
    if (a=='+' || a=='-'){
        if (b=='x' || b== '/') {
            return true;
        }        
    }
    return false;
}

int calc(int a, char o, int b) {
    int res;
    switch (o)
    {
    case '+':
        return a+b;
        break;
    case 'x':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    case '-':
        return a-b;
        break;
    default:
        break;
    }
}