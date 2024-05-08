// TOP - DOWN   :: RECURSION + MEMOIZATION

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int recurse(int n) {
        if(n==0||n==1) return n;

        return recurse(n-1)+recurse(n-2);
    }
    
    int fib(int n) {
        return recurse(n);
    }
};