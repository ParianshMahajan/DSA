#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *prev;
    int a;
    node *next;

    //constructor
    node(){
        prev=NULL;
        next=NULL;
    }
    node(int d){
        a=d;
        prev=NULL;
        next=NULL;
    }

    //Destructor
    ~node(){
        int value=a;
        //Memory free
        if(next!=NULL||prev!=NULL){
            delete next;
            delete prev;
            next=NULL;
            prev=NULL;
        }
        cout<<"Memory of node with the value "<<value<<" is freed."<<endl;
    }

};



//Insertion
void insert_at_tail(node *&tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insert_at_head(node *&head,int d){
    node *temp=new node(d);
    head->prev=temp;
    temp->next=head;
    head=temp;
}

//midinsertion
void insert_at_mid(node* &head,int d,int n){
    node *temp=head;
    node *ins=new node(d);

    if(n==1){
        ins->next=head;
        head->prev=ins;
    }
    else{
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }
        ins->next=temp->next;
        ins->prev=temp;
        temp->next=ins;
    }

}


//Deletion
void del(node *&head,int n){
    node *temp=head;
    if(n==1){
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }
        node *mem=temp->next;
        temp->next=mem->next;
        if(mem->next!=NULL){
            (mem->next)->prev=temp;
        }
        mem->prev=NULL;
        delete mem;
    }

}

//traverse
void for_trav(node *&head){

}

void back_trav(node *&tail){

}



int main(){
    node *n1=new node(10);
    node *head=n1;          // At initialisation, the single node is both head and tail.
    node *tail=n1;
    
    //Insertion at head
    insert_at_head(head,9);
    insert_at_head(head,8);

    //Insertion at head
    insert_at_tail(tail,11);
    insert_at_tail(tail,12);

    for_trav(head);
    cout<<endl;
    back_trav(tail);  
    cout<<endl;

    //Insertion at mid
    insert_at_mid(head,100,4);
    for_trav(head);

    cout<<endl;

    //Deletion
    del(head,6);
    for_trav(head);
    
    return 0;
}