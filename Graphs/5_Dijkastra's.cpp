#include<bits/stdc++.h>
using namespace std; 


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,list<pair<int,int>>>adj;
    
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];


        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }



    vector<int>ans(vertices,INT_MAX);

    set<pair<int,int>>st;
    
    st.insert(make_pair(0,source));
    ans[source]=0;

    while(!st.empty()){

        // top Node
        auto top=*(st.begin());
        st.erase(st.begin());

        for(auto i:adj[top.second]){
            if((top.first+i.second)<ans[i.first]){
                
                auto record=st.find(make_pair(ans[i.first],i.first));
                if(record !=st.end()){
                    // record found ---> erase it
                    st.erase(record);

                };
                

                // update distance
                ans[i.first]=top.first+i.second;
                // push new record in set
                st.insert(make_pair(ans[i.first],i.first));
            }
        }
    
    }
    
    return ans;

}
