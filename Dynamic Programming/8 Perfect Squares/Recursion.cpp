// RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(int n) {
        if(n==0)return 0;
        if(n<0)return INT_MAX;

        int mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ans=recurse(n-(i*i));
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }

        return mini;


    }

    int numSquares(int n) {
        return recurse(n);
    }
};