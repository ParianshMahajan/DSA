// BOTTOM - UP   :: TABULATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        if(nums.size()>1) dp[1]=max(nums[1],nums[0]);


        for(int i=2;i<nums.size();i++){
            
            int inc=dp[i-2]+nums[i];            
            int exc=dp[i-1]+0;

            dp[i]=max(inc,exc);            
        }

        return dp[nums.size()-1];
    }
};