// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int recurse(int n, int x, int y, int z,vector<int>&dp) {
	if(n<0) return INT_MIN;
	if(n==0) return 0;

	if(dp[n]!=-1) return dp[n];
	
	// including x
	int a=recurse(n-x,x,y,z,dp);
	// including y
	int b=recurse(n-y,x,y,z,dp);
	// including z
	int c=recurse(n-z,x,y,z,dp);

	dp[n]=max(a,max(b,c));
	return dp[n];

}
int cutSegments(int n, int x, int y, int z) {
	vector<int>dp(n+1,-1);
	int ans=recurse(n,x,y,z,dp);
	if(ans==INT_MIN) return 0;
	return ans;
}