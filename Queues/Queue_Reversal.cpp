#include<bits/stdc++.h>
using namespace std;

// APpproach 1


class Solution
{
    public:
    queue<int> rev(queue<int> &q)
    {
        if(q.empty()){
            return q;
        }

        int num=q.front();
        q.pop();
        rev(q);
        q.push(num);

        return q;

    }
};






//Approach 2;
class Solution
{
    public:
    queue<int> rev(queue<int> &q)
    {
        stack<int>s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        return q;

    }
};