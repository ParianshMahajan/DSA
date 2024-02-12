#include<bits/stdc++.h>
using namespace std;




// O(log N)
void heapify(int arr[],int n,int i){

    int curr=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[curr]<arr[left]){
        curr=left;
    }
    if(right<n && arr[curr]<arr[right]){
        curr=right;
    }

    // if UPDATED
    if(curr!=i){
        swap(arr[curr],arr[i]);
        heapify(arr,n,curr);
    }
}



// O(N) 
void buildHeap(int arr[],int n){
    for(int i=n/2-1;i>0;i--){
        heapify(arr,n,i);    
    }
}



// O(N) 
void heapSort(int arr[],int n){
    
    for (int i = n- 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }


}


int main(){
    int arr[4]={5,2,3,1};
    int n=4;

    buildHeap(arr,n);
    heapSort(arr,n);
        
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}