#include<bits/stdc++.h>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};




//Creation BT
node* createTree(node* root){
    
    cout<<"Enter the values :"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter value for inserting in left to  "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter value for inserting in right to  "<<data<<endl;
    root->right=createTree(root->right);
    return root;
}







//print BT
void printTree(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }

}



int main(){
    node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root=createTree(root);

    printTree(root);
    return 0;
}