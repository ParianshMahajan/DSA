#include<bits/stdc++.h>
using namespace std;

bool reverse(string &name,int s,int e){
    if(s>=e){
        return true;
    }
    if(name[s]!=name[e]){
        return false;
    }
    return reverse(name,++s,--e);
} 



int main(){
    
    string s="BookkooB";

    cout<<reverse(s,0,s.length()-1);

    return 0;
}