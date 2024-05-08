#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m,vector<vector<int>> &visited,int n,int x,int y) {
        if(y>=0&&y<n&&x>=0&&x<n&&visited[x][y]==0&&m[x][y]==1){
            return true;
        }        
        return false;
    }

    
    
    void recurse(vector<vector<int>> &m,string temp, vector<string>&ans,vector<vector<int>> &visited,int n,int x,int y) {
        if(!isSafe(m,visited,n,x,y)) return;
        if(x==n-1&&y==n-1){
            ans.push_back(temp);
            return;
        }
        
        visited[x][y]=1;
        // left
        if(isSafe(m,visited,n,x,y-1)){
            temp.push_back('L');
            recurse(m,temp,ans,visited,n,x,y-1);
            temp.pop_back();
        }
        
        // Upward
        if(isSafe(m,visited,n,x-1,y)){
          temp.push_back('U');
            recurse(m,temp,ans,visited,n,x-1,y);
            temp.pop_back();
        }
        
        // downward
        if(isSafe(m,visited,n,x+1,y)){
           temp.push_back('D');
            recurse(m,temp,ans,visited,n,x+1,y);
            temp.pop_back();
        }
        // right
        if(isSafe(m,visited,n,x,y+1)){
           temp.push_back('R');
            recurse(m,temp,ans,visited,n,x,y+1);
            temp.pop_back();
        }
        
        visited[x][y]=0; 
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>visited=m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;            
            }
        }

        string temp;
        recurse(m,temp,ans,visited,n,0,0);        
        return ans;   
    }
};
