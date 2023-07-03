//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string expr)
    {
        // Your code here
         stack<char> temp;
        for (int i = 0; i < expr.length(); i++) {
            if (temp.empty()) {
                 
                // If the stack is empty
                // just push the current bracket
                temp.push(expr[i]);
            }
            else if ((temp.top() == '(' && expr[i] == ')')
                     || (temp.top() == '{' && expr[i] == '}')
                     || (temp.top() == '[' && expr[i] == ']')) {
                 
                // If we found any complete pair of bracket
                // then pop
                temp.pop();
            }
            else {
                temp.push(expr[i]);
            }
        }
        if (temp.empty()) {
             
            // If stack is empty return true
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends