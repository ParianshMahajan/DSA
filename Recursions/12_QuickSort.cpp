#include<bits/stdc++.h>
using namespace std;


// Method 2 of pivoting
int pivoting2(vector<int> &v,int s,int e){
   int pivot=v[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(v[i]<=pivot){
            count++;
        }
    }

    int pivotindex=s+count;
    swap(v[s],v[pivotindex]);

    // since pivoting has been done arranging left and right part
    int i=s,j=e;

    while(i<pivotindex&&j>pivotindex){
        while(v[i]<pivot) i++;
        while(v[j]>pivot) j--;

        if(i<pivotindex&&j>pivotindex) swap(v[i++],v[j--]);
    }

    return pivotindex;
}






// Method1 of pivoting
int pivoting1(vector<int> &v,int s,int e){
   int pivot=v[e];
    int i=s-1;
    for(int j=s;j<=e;j++){
        if(v[j]<pivot){
            swap(v[++i],v[j]);
        }
    }

    swap(v[++i],v[e]);
    return i;


}



void quickSort(vector<int> &v,int s,int e){

    if(s>=e){
        return;
    }
    int p=pivoting2(v,s,e);
    quickSort(v,s,p-1);
    quickSort(v,p+1,e);

}



int main(){
    vector<int>v={22,43,12,32,23,68,45,34,98,65,34,27,39,21,43};    

    quickSort(v,0,v.size()-1);

    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}