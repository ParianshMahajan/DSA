// RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>&nums,int target){
        if(target==0) return 1;
        if(target<0) return 0;


        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=recurse(nums,target-nums[i]);
        }

        return count;


    }

    int combinationSum4(vector<int>& nums, int target) {
        return recurse(nums,target);
    }
};