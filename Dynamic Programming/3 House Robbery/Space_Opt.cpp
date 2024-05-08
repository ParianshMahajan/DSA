// SPACE OPTIMISATION :: ONLY VARIABLES

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {
         int x=nums[0],y;
        if(nums.size()>1) y=max(nums[1],nums[0]);
        else return x;

        for(int i=2;i<nums.size();i++){
            
            int inc=x+nums[i];            
            int exc=y+0;

            x=y;
            y=max(inc,exc);
        }

        return y;
    }
};