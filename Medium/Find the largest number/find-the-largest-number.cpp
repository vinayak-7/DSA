//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check(int n)
    {
        if(n<10)
        {
            return true;
        }
        
        int res=n%10;
        
        n=n/10;
        
        while(n)
        {
            int temp=n%10;
            if(temp>res)
            {
                return false;
            }
            res=temp;
            n=n/10;
        }
        
        return true;
    }
    
    int find(int N){
        // code here
        
        for(int i = N ; i >=1 ; i--)
        {
            if(check(i)==true)
            {
                return i;
            }
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends