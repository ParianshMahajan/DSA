// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int recurse(int n,vector<int>&dp) {
        if(n==0||n==1) return n;

        if(dp[n]!=-1) return dp[n];

        dp[n]=recurse(n-1,dp)+recurse(n-2,dp);
        return dp[n];
        
    }
    
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return recurse(n,dp);
    }
};