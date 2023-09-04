#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;
    s.push(2);    
    s.push(5);    
    s.push(6);    

    cout<<s.size()<<endl;                                                     //size of stack

    cout<<s.top()<<endl;                                                  // return top element that is 6 last enetered on the top
    
    s.pop();                                                        //Pops up the top element;

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;

    return 0;
}