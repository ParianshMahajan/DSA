// RECURSION

#include<bits/stdc++.h>
using namespace std;

int recurse(vector<int> weight, vector<int> value, int index,int W){
    if(W<0)return INT_MIN;
    if(W==0||index>=weight.size()) return 0;
    
    
    
	// carry 
    int incl=recurse(weight,value,index+1,W-weight[index])+value[index];
    
	// not carry
    int excl=recurse(weight,value,index+1,W);
    

	return max(incl,excl);
} 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return recurse(weight,value,0,maxWeight);
}