// BOTTOM - UP   :: TABULATION

#include<bits/stdc++.h>
using namespace std;


int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n,1));

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }

        return dp[m-1][n-1];

}