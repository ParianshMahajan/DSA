#include<bits/stdc++.h>
using namespace std;




void mergeArray(vector<int> &v,int s,int mid,int e){
    int len1=mid-s+1;
    int len2=e-mid;

    int arr1[len1];
    int arr2[len2];
    int x=s;

    for(int i=0;i<len1;i++){
        arr1[i]=v[s+i];
    }
    for(int i=0;i<len2;i++){
        arr2[i]=v[i+mid+1];
    }

    int i=0,j=0;
    while(i<len1&&j<len2){
        if(arr1[i]<arr2[j]){
            v[x++]=arr1[i++];
        }
        else{
            v[x++]=arr2[j++];
        }
    }
    while(i<len1){
        v[x++]=arr1[i++];
    }
    while(j<len2){
        v[x++]=arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}



void mergeSort(vector<int> &v,int s,int e){

    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    mergeArray(v,s,mid,e);

}



int main(){
    vector<int>v={22,43,12,32,23,68,45,34,98,65,34,27,39,21,43};    

    mergeSort(v,0,v.size()-1);

    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}