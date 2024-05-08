// BOTTOM - UP   :: TABULATION

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j*j<=n;j++){
                if(i>=j*j&&dp[i-(j*j)]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[i-(j*j)]);
            }
        }
        return dp[n];
    }
};