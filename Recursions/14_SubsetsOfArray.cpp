#include<bits/stdc++.h>
using namespace std;

// Recusion

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





// Bits Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){              // 1<<n means 2^n
            vector<int>v;
            for(int j=0;j<n;j++){              
                if((1<<j)&i){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};