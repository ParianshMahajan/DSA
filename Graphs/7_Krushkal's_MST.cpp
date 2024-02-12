#include<bits/stdc++.h>
using namespace std;



void initialise(vector<int>&parent,vector<int>&rank,int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		rank[i]=0;
	}
}

int findParent(vector<int>&parent,int node){
	if(parent[node]==node){
		return node;
	}
	return parent[node]=findParent(parent, parent[node]);
}

void unionSet(vector<int> &rank,vector<int> &parent,int u, int v){
	u=findParent(parent,u);
	v=findParent(parent,v);

	if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}

}

bool cmp(vector<int>&a,vector<int>&b){
	return a[2]<b[2];
}


int kruskalMST(int n, vector<vector<int>> &edges)
{

	sort(edges.begin(),edges.end(),cmp);
	vector<int> parent(n);
	vector<int> rank(n);
	initialise(parent,rank,n);

	int minWeight=0;

	for(int i=0;i<edges.size();i++){
		int u=findParent(parent,edges[i][0]);
		int v=findParent(parent,edges[i][1]);

		if(u!=v){
			minWeight+=edges[i][2];
			unionSet(rank,parent,u,v);
		}

	}
	return minWeight;
}
