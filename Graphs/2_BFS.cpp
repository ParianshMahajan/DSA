#include<bits/stdc++.h>
using namespace std;






vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> ans;
    map<int, bool> visited;

    map<int, list<int>> adjlist;

    for(auto i:adj){
        adjlist[i[0]].push_back(i[1]);
        adjlist[i[1]].push_back(i[0]);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()){

                int frontNode = q.front();
                q.pop();

                ans.push_back(frontNode);

                for(auto j : adjlist[frontNode]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    return ans;
}

int main(){

    int m,n;
    cout<<"Enter the number of nodes :: ";
    cin>>n;
    
    cout<<"Enter the number of edges :: ";
    cin>>m;

    vector<vector<int>>adj;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        vector<int>x={u,v};
        adj.push_back(x);
    }
    for(int i:bfsTraversal(n,adj)){
        cout<<i<<" ";
    }


    return 0;
}