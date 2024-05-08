// RECURSION

#include<bits/stdc++.h>
using namespace std;

#define Mod 1000000007

long long int recurse(int n){
    if(n==1) return 0; 
    if(n==2) return 1;

    long long int ans=(n-1)%Mod*((recurse(n-1)%Mod+recurse(n-2)%Mod)%Mod);
    return ans%Mod;

}



long long int countDerangements(int n) {
    return recurse(n);
}