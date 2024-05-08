// RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>&nums,int val,int index){
        if(index>=nums.size()) return 0;

        // include
        int incl=INT_MIN;
        if(val<nums[index]){
            incl=recurse(nums,nums[index],index+1)+1;
        }
        // exclude
        int excl=recurse(nums,val,index+1);

        return max(incl,excl);
    }

    int lengthOfLIS(vector<int>& nums) {
        return recurse(nums,INT_MIN,0);
    }
};