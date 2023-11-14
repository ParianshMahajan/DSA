//
// Inorder -> Left-Node-Right
// PreOrder -> Node-Left-Right
// PostOrder -> Left-Right-Node
//


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







//Inorder BT (LNR)
void InorderTree(node* temp){
    
    if(temp->left){
        InorderTree(temp->left);
    }
    
    cout<<temp->data<<" ";


    if(temp->right){
        InorderTree(temp->right);
    }

}


//Preorder BT (LNR)
void PreorderTree(node* temp){
    
    cout<<temp->data<<" ";
    if(temp->left){
        PreorderTree(temp->left);
    }


    if(temp->right){
        PreorderTree(temp->right);
    }

}





//Postorder BT (LNR)
void PostorderTree(node* temp){
    
    if(temp->left){
        PostorderTree(temp->left);
    }


    if(temp->right){
        PostorderTree(temp->right);
    }

    cout<<temp->data<<" ";
}



int main(){
    node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root=createTree(root);

    node* temp=root;
    InorderTree(temp);
    cout<<endl;
    
    temp=root;
    PreorderTree(temp);
    cout<<endl;

    temp=root;
    PostorderTree(temp);

    return 0;
}