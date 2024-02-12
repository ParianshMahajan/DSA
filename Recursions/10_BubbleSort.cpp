#include<bits/stdc++.h>
using namespace std;


void bubbSort(vector<int>&v,int n){

    if(n==0||n==1) return;


    for(int i=0;i<n-1;i++){
        if(v[i+1]<v[i]){
            swap(v[i+1],v[i]);
        }
    }
    
    bubbSort(v,n-1);
}

int main(){
    
    vector<int>v={3,4,1,3,6,2,1,7,8,2,3};

    bubbSort(v,v.size());

    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}