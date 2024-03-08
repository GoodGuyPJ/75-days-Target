//queue Reversal
i/p -> 4 3 2 1
o/p -> 1 2 3 4 5

using Stack -- Approach 1
//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
         stack<int> s;
         while(!q.empty()){
             int element = q.front();
             q.pop();
             s.push(element);
         }
         while(!s.empty()){
             int element = s.top();
             s.pop();
             q.push(element);
         }
         return q;
    }
};




using Recursion -- Approach 2
//Function to reverse the queue.
class Solution
{
     void reverse(queue<int>& q){
         if(q.size() == 0) return;
          int ele = q.front();
         q.pop();
         reverse(q);
         q.push(ele);
          
     }
    public:
    queue<int> rev(queue<int> q)
    {
         reverse(q);
         return q;
    }
};



