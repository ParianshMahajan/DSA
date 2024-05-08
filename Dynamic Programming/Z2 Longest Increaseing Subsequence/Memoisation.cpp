// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>&nums,int prevIndex,int index,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index][prevIndex+1]!=-1)return dp[index][prevIndex+1];

        // include
        int incl=INT_MIN;
        if(prevIndex==-1 || nums[prevIndex]<nums[index]){
            incl=recurse(nums,index,index+1,dp)+1;
        }
        // exclude
        int excl=recurse(nums,prevIndex,index+1,dp);

        dp[index][prevIndex+1]=max(incl,excl);
        return max(incl,excl);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return recurse(nums,-1,0,dp);
    }
};