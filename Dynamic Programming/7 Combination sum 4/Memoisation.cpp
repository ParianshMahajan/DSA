// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>&nums,int target,vector<int>&dp){
        if(target==0) return 1;
        if(target<0) return 0;

        if(dp[target]!=-1)return dp[target];

        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=recurse(nums,target-nums[i],dp);
        }
        
        dp[target]=count;
        return count;


    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return recurse(nums,target,dp);
    }
}; 