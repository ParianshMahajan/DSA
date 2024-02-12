#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
   
    ListNode* findMid(ListNode*head){
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }

        return slow;
    }


    ListNode* merge(ListNode* left,ListNode* right){
        ListNode *temp1=left;
        ListNode *temp2=right;
        
        ListNode *save=NULL;
        if(left->val >= temp2->val){
            save=temp2;
            temp2=temp2->next;
            save->next=left;
            left=save;
            temp1=left;
        }
        while(temp1->next!=NULL && temp2!=NULL){
            if(temp2->val<=temp1->next->val){
                save=temp1->next;
                temp1->next=temp2;
                temp2=temp2->next;
                temp1->next->next=save;
                temp1=temp1->next;                
            }
            else{
                temp1=temp1->next;
            }
        }
        if(temp2!=NULL){
            temp1->next=temp2;
        }

        return left;
    } 

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;


        ListNode *mid=findMid(head);
        
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;

        //sorting left
        left=sortList(left);
        right=sortList(right);

        //merging
        return merge(left,right);

    }
};