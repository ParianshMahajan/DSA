// RECURSION

#include<bits/stdc++.h>
using namespace std;

int recurse(int n, int x, int y, int z) {
	if(n<0) return INT_MIN;
	if(n==0) return 0;


	// including x
	int a=recurse(n-x,x,y,z);
	// including y
	int b=recurse(n-y,x,y,z);
	// including z
	int c=recurse(n-z,x,y,z);

	return max(a,max(b,c));

}
int cutSegments(int n, int x, int y, int z) {
	int ans=recurse(n,x,y,z);
	if(ans==INT_MIN) return 0;
	return ans;
}