// BOTTOM - UP   :: TABULATION

#include<bits/stdc++.h>
using namespace std;


#define Mod 1000000007

long long int countDerangements(int n) {
    vector<long long int>dp(n+1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=((i-1)*(((dp[i-1]%Mod)+(dp[i-2]%Mod))%Mod)%Mod);
    }
    return dp[n]%Mod;
}