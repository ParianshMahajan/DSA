#include<bits/stdc++.h>
using namespace std;


int binSrch(vector<int>v,int s,int e,int key){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;

    if(v[mid]==key){
        return mid+1;
    }
    else if(v[mid]>key){
        return binSrch(v,0,mid-1,key);
    }
    else{
        return binSrch(v,mid+1,e,key);
    }
}

int main(){
    vector<int>v={0,1,2,8,9,12,16,18};
    int key;
    cin>>key;

    cout<< binSrch(v,0,v.size()-1,key);

    return 0;
}