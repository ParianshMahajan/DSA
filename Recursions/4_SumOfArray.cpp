#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int sumn(int arr[],int n){
     
     if(n==0)
     return 0;

     return arr[n-1]+sumn(arr,n-1);

}


int main(){
     int arr[5]={0,1,3,4,5};
     cout<<sumn(arr,5);
     return 0;
}