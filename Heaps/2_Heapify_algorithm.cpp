#include<bits/stdc++.h>
using namespace std;





// O(log N)
void heapify(int arr[],int size,int i){

    int curr=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && arr[curr]<arr[left]){
        curr=left;
    }
    if(right<size && arr[curr]<arr[right]){
        curr=right;
    }

    // if UPDATED
    if(curr!=i){
        swap(arr[curr],arr[i]);
        heapify(arr,size,curr);
    }

}



// O(N) 
void buildHeap(int arr[],int size){
    
    for(int i=0;i<size/2;i++){
        heapify(arr,size,i);    
    }
}


int main(){
    int arr[5]={54,53,55,52,50};
    int size=5;


    buildHeap(arr,size);
        
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}