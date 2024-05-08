#include<bits/stdc++.h>
using namespace std;



#define Mod 1000000007

long long int countDerangements(int n) {
    long long int x=0;
    long long int y=1;
    for(int i=3;i<=n;i++){
        int c=((i-1)*(((x%Mod)+(y%Mod))%Mod)%Mod);
        x=y;
        y=c;
    }
    return y%Mod;
}