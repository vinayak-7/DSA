//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long game(long long int n,vector<int> &opt , int i)
{
    if(n==0) return 1;
    if(i < 0) return n == 0;
    
    long long move = n - opt[i] >= 0 ? game(n-opt[i],opt,i): 0;
    long long dontMove = game(n,opt,i-1);
    
    return move+dontMove;
}
long long int count(long long int n)
{
	vector<int> opt{3,5,10};
	
	return game(n,opt,2);
	
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends