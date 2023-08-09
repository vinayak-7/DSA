//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int gcd(int a , int b)
    {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>, int> m;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int d = gcd(numerator[i], denominator[i]);
            
            int a=numerator[i]/d;
            int b=denominator[i]/d;
            int c=b-a;
            
            if(m.count({c,b}))
             ans+=m[{c,b}];
             
            m[{a,b}]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends