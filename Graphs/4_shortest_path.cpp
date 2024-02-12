#include<bits/stdc++.h>
using namespace std;



vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>>adj;
	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;

	for(auto i:edges){
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}


	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){
		int frontNode=q.front();
		q.pop();
		for(auto i:adj[frontNode]){
			if(!visited[i]){
				q.push(i);
				parent[i]=frontNode;
				visited[i]=true;
			}
		}
	}
	vector <int> ans;
	ans.push_back(t);
	int curr=t;
	while(curr!=s){
		curr=parent[curr];
		ans.push_back(curr);
	}

	reverse(ans.begin(),ans.end());
	return ans;

}



int main(){
    
    int m,n;
    cout<<"Enter the number of nodes :: ";
    cin>>n;
    
    cout<<"Enter the number of edges :: ";
    cin>>m;

    vector<pair<int,int>>adj;

    int s,t;
    cout<<"ENter the starting and enting point ::-"<<endl;
    cin>>s>>t;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj.push_back(make_pair(u,v));
    }
    for(auto i:shortestPath(adj,n,m,s,t)){

        cout<<i<<" ";
    
    }
    cout<<endl;

    return 0;
}