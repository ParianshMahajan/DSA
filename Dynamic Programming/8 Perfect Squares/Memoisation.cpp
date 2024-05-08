// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(int n,vector<int>&dp) {
        if(n==0)return 0;
        if(n<0)return INT_MAX;

        if(dp[n]!=-1) return dp[n];

        int mini=INT_MAX;
        for(int i=1;i*i<=(n);i++){
            int ans=recurse(n-(i*i),dp);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        dp[n]=mini;
        return mini;


    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return recurse(n,dp);
    }
};