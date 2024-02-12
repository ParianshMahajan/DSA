#include<bits/stdc++.h>
using namespace std;

int srch(int *arr,int n,int key){
     if(n<=0){
          return -1;
     }

     if(arr[n-1]==key){
          return n;
     }

     return srch(arr,n-1,key);
}


int main(){
     int key;
     cin>>key;
     int arr[5]={0,1,3,4,5};
     int ans=srch(arr,5,key);

     if(ans<0)
     cout<<"Key Not Found";
     else
     cout<<"Key Found at position "<<ans;
     return 0;
}