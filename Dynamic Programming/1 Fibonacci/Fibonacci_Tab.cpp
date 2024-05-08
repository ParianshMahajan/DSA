// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int recurse(int n,vector<int>&dp) {

        if(dp[n]!=-1) return dp[n];

        dp[n]=dp[n-1]+dp[n-2];
        return dp[n];
        
    }
    
    int fib(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return recurse(n,dp);
    }
};