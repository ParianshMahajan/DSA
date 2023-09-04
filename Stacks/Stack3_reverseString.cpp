#include<bits/stdc++.h>
using namespace std;


int main(){
    string s="Pariansh";
    stack<char> st;
    string ans="";

    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    while(! st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    cout<<ans;

    return 0;
}