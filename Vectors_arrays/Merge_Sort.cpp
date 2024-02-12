#include<bits/stdc++.h>
using namespace std;



class Solution {
public:



    void mergeArray(vector<int>& nums,int s,int mid,int e){
        vector<int> left(mid-s+1);
        vector<int> right(e-mid);

        for(int i=0;i<left.size();i++){
            left[i]=nums[s+i];
        }
        for(int i=0;i<right.size();i++){
            right[i]=nums[mid+i+1];
        }
        int i=0,j=0,x=s;
        while(i!=left.size()&&j!=right.size()){
            if(left[i]>right[j]){
                nums[x++]=right[j++];
            }
            else{
                nums[x++]=left[i++];
            }
        }
        if(i<left.size()){
            nums[x++]=left[i++];
        }
        if(j<right.size()){
            nums[x++]=right[j++];
        }
    }   



    void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=s+((e-s)/2);
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);

        mergeArray(nums,s,mid,e);
    }



    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        mergeSort(nums,s,e);
        return nums;
    }
};