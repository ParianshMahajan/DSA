#include<bits/stdc++.h>
using namespace std;

void reverse(string &name,int s,int e){
    if(s>=e){
        return;
    }
    swap(name[s],name[e]);
    reverse(name,++s,--e);
} 



int main(){
    
    string s="Parianshm";

    reverse(s,0,s.length()-1);

    cout<<s;
    return 0;
}