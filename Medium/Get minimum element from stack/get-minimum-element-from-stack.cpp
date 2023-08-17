//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()){
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
            if(s.size() == 0) return -1;
            
            int curr = s.top();
            if(s.top() >= minEle){
                s.pop();
                return curr;
            }
            else if(s.top() < minEle)
            {
                int premin = minEle;
                minEle = 2*minEle - s.top();
                s.pop();
                return premin;
                
            }
       }
       
       /*push element x into the stack*/
       void push(int val){
           
           //Write your code here
            if(s.size() == 0)
            {
                s.push(val);
                minEle = val;
            }
            else if(val>=minEle) s.push(val);
            else if(val<minEle)
            {
                s.push(2*val - minEle);
                minEle = val;
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends