// RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurse(int x,int y,int m,int n,map<pair<int,int>,bool> visited,int &ans){
        if((x>=m||y>=n)||visited[make_pair(x,y)]==true) return;
        if(x==m-1&&y==n-1){
            ans++;
            return ;
        }

        visited[make_pair(x,y)]=true;
        // moving right
        if(y+1<n&&visited[make_pair(x,y+1)]==false){
            recurse(x,y+1,m,n,visited,ans);
        }
        // moving down
        if(x+1<m&&visited[make_pair(x+1,y)]==false){
            recurse(x+1,y,m,n,visited,ans);
        }


    }

    int uniquePaths(int m, int n) {
        int ans;
        map<pair<int,int>,bool> visited;

        recurse(0,0,m,n,visited,ans);
        return ans;
    }
};