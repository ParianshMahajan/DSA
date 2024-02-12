#include<bits/stdc++.h>
using namespace std;



int inversionCount(vector<int> &v){

    int count=0;    
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j]){
                count++;
            }
        }
    }

    return count;
}



int main(){
    vector<int>v={2, 4, 1, 3, 5};    

    cout<<inversionCount(v);


    return 0;
}