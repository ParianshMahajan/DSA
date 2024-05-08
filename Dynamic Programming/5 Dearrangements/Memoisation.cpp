// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

#define Mod 1000000007

long long int recurse(int n,vector<long long int>&dp){
    if(n==1) return 0; 
    if(n==2) return 1;
    if(dp[n]!=-1)return dp[n];

    dp[n]=(n-1)%Mod*((recurse(n-1,dp)%Mod+recurse(n-2,dp)%Mod)%Mod);
    return dp[n]%Mod;

}



long long int countDerangements(int n) {
    vector<long long int>dp(n+1,-1);
    return recurse(n,dp);
}