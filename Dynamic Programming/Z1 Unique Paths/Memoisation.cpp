// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int top=recurse(i-1,j,dp);
        int left=recurse(i,j-1,dp);

        dp[i][j]=top+left;
        return dp[i][j];


    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1)); // memoisation
        return recurse(m-1,n-1,dp); 
    }
};