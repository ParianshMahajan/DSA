// RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int recurse(vector<int>& nums,int i) {
        if(i>=nums.size()) return 0;


        // including i
        int s1=recurse(nums,i+2)+nums[i];
        
        // excluding i
        int s2=recurse(nums,i+1)+0;

        return max(s1,s2);

    }



    int rob(vector<int>& nums) {
        return recurse(nums,0);
    }
};