#include<bits/stdc++.h>
using namespace std;


void formSubset(vector<int>& nums,vector<int> temp,int i,vector<vector<int>>& ans) {
    if(i>=nums.size()){
        ans.push_back(temp);
        return;
    }
    // Excluding i
    formSubset(nums,temp,i+1,ans);

    // Including i
    temp.push_back(nums[i]);
    formSubset(nums,temp,i+1,ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    formSubset(nums,temp,0,ans);
    return ans;
}