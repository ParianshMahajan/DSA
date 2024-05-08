// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

int recurse(vector<int> weight, vector<int> value, int index,int W,vector<vector<int>>&dp){
    if(W<0)return INT_MIN;
    if(W==0||index>=weight.size()) return 0;
    
	if(dp[index][W]!=-1) return dp[index][W];
    
    
	// carry 
    int incl=recurse(weight,value,index+1,W-weight[index],dp)+value[index];
    
	// not carry
    int excl=recurse(weight,value,index+1,W,dp);
    

	dp[index][W]=max(incl,excl);
	return max(incl,excl);
} 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return recurse(weight,value,0,maxWeight,dp);
}