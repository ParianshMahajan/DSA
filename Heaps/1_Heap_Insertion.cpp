#include<bits/stdc++.h>
using namespace std;


class heap{
    public:
      int arr[100];
      int size=0;

    heap(){
        arr[0]=-1;
        size=0;
    }



    //INSERTION [ T.c = O(logn) ]
    void insert(int val){

        // step 1 :- insert value at array's end;
        
        size++;
        int index=size;
        arr[index]=val;

        // step2 :- keep comparing the heap order property
        // Here max heap
        while (index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }





    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }



    // DELETION means deletion of root
    void deletion(){
        if(size==0){
            cout<<"Heap is empty. Nothing to delete";
            return;
        }

        // step 1 :- copyy the value of last node to root node 
        arr[1]=arr[size];

        // step 2 :- remove last node
        size--;

        // step 3 :- propogate root node to its right position acc to its heap property 
        // here max heap it is
        int index=1;
        while(index<size){
            int leftIndex=index*2;
            int rightIndex=index*2+1;

            if(leftIndex<size  && arr[index]<arr[leftIndex]){
                swap(arr[index],arr[leftIndex]);
                index=leftIndex;
            }
            else if(rightIndex<size  && arr[index]<arr[rightIndex]){
                swap(arr[index],arr[rightIndex]);
                index=rightIndex;
            }
            else{
                return ;
            }
        }


    }


};



int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletion();
    h.print(); 

    return 0;
}