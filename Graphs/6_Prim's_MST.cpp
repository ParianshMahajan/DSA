#include<bits/stdc++.h>
using namespace std; 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    unordered_map<int,list<pair<int,int>>>adj;

    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    int source=1;

    key[source]=0;
    parent[source]=-1;

    for(int i=0;i<=n;i++){
        int mini=INT_MAX;
        int u;

        // calculating u (the min weighted node);
        for(int j=0;j<=n;j++){
            if(mst[j]==false&&key[j]<mini){
                u=j;
                mini=key[j];
            }
        }

        // UPDATING THE U's Values
        mst[u]=true;


        // Finding ADJACENT
        for(auto j:adj[u]){
            if(mst[j.first]==false&&j.second<key[j.first]){
                parent[j.first]=u;
                key[j.first]=j.second;
            }
        }
    }

    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }

    return ans;
    

}
