#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int s[114514];
    int i=0;
    for (i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    sort(&s[0],&s[n]);
    int num,tot,ed;
    num=tot=1;
    ed=0;
    for (i=1;i<n;i++){

        if (s[i]==s[i-1]){
            num+=1;
        }
        else{
            num=1;
        }
        if(tot<num){
            tot=num;
            ed=i;
        }
    }
    printf("%d",s[ed]);
    return 0;
}