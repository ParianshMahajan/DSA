#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
long long int solve(vector<int>& nums){
    long long int prev2=0;
    long long int prev1=nums[0];

    for(long long int i=1;i<nums.size();i++){
        long long int inc=prev2+nums[i];
        long long int exc=prev1+0;
        

        prev2=prev1;
        prev1=max(inc,exc);

    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if (n==1) return valueInHouse[0];

    vector<int>first,second;
    for(long long int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    } 

    return max(solve(first),solve(second));
}