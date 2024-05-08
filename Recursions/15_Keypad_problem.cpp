#include<bits/stdc++.h>
using namespace std;



// Recursion 

class Solution {
public:

    void formSet(string digits,vector<string>&ans,string t,int index,map<char,string>m){
        if(index>=digits.length()){
            ans.push_back(t);
            return;
        }

        for(int i=0;i<m[digits[index]].length();i++){
            t.push_back(m[digits[index]][i]);
            formSet(digits,ans,t,index+1,m);
            t.pop_back();
        }

    }

    vector<string> letterCombinations(string digits){
         map<char,string>m;
    char st='a';
    for(int i=2;i<=9;i++){
        string t="";
        t.push_back(st++);
        t.push_back(st++);
        t.push_back(st++);
        if(i==7||i==9) t.push_back(st++);
        m[i+'0']=t;
    };

        vector<string>ans;
        if(digits==""){
            return ans;
        }
        string t="";
        formSet(digits,ans,t,0,m);


        return ans;
    }
};






// LOOP
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string>m;
        char st='a';
        for(int i=2;i<=9;i++){
            string t="";
            t.push_back(st++);
            t.push_back(st++);
            t.push_back(st++);
            if(i==7||i==9) t.push_back(st++);
            m[i+'0']=t;
        };


        vector <string> tans;
        if(digits==""){
            return tans;
        }
        
        
        int length=1;
        for(int i=0;i<digits.length();i++){
            length*=m[digits[i]].length();
        }
        
        vector <string> output(length,"");
        int temp=length; 
        
        
        
        for(int i=0;i<digits.length();i++){
            temp= temp/m[digits[i]].length();
            
            int index=0;
            int count=0;
            for(int j=0;j<length;j++){
                if(count==temp){
                    count=0;
                    index++;
                }
                if(index==m[digits[i]].length()){
                    index=0;
                }
                count++;
                output[j].push_back(m[digits[i]][index]);
            }
        }

        return output;
    }
};