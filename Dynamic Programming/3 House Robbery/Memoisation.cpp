// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int recurse(vector<int>& nums,int i,vector<int>&dp) {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];


        // including i
        int s1=recurse(nums,i+2,dp)+nums[i];
        
        // excluding i
        int s2=recurse(nums,i+1,dp)+0;

        dp[i]=max(s1,s2);
        return max(s1,s2);

    }



    int rob(vector<int>& nums) {
       vector<int>dp(nums.size()+1,-1);
        return recurse(nums,0,dp);
    }
};