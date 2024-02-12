#include<bits/stdc++.h>
using namespace std;


int OptSqr(int num,int b){
    if(b==0) return 1;
    
    if(b%2==0){
        // even
        return OptSqr(num,b/2)*OptSqr(num,b/2);
    }
    else{
        // odd
        return num*OptSqr(num,b/2)*OptSqr(num,b/2);
    }
}


int main(){
    int num=3,b=4;
    
    cout<<OptSqr(num,b);

    return 0;
}