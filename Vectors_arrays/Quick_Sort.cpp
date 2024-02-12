#include<bits/stdc++.h>
using namespace std;




class Solution {
public:



    int partition(vector<int>& nums,int s,int e){
        int p=s;
        int count=0;
        for(int i=s+1;i<=e;i++){
            if(nums[i]<=nums[p]){
                count++;
            }
        }
        swap(nums[s+count],nums[p]);
        //new pivotIndex;
        p=s+count;

        int i=s,j=e;
        while(i<p&&j>p){
            while(nums[i]<nums[p]){
                i++;
            }
            while(nums[j]<nums[p]){
                j--;
            }
            if(i<p&&j>p){
                swap(nums[i++],nums[j--]);
            }
        }

        return p;
    }   



    void quickSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int p=partition(nums,s,e);
        quickSort(nums,s,p-1);
        quickSort(nums,p+1,e);
    }



    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        quickSort(nums,s,e);
        return nums;
    }
};

