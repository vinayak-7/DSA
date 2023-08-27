//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

int findEqualPoint(int arr[], int n) ;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n]={0};
		for(int i = 0; i < n; i++)
		cin>>arr[i];
		
		cout<< findEqualPoint(arr, n) <<endl;
	}
	
	return 0;
}

// } Driver Code Ends


int findEqualPoint(int arr[], int n) 
{
    // Your code goes here
    if(n==1) return 0;
    
    int k=1;
    for(int i=1;i<n;i++){
     if(arr[i]!=arr[i-1]) k++;
    }


    if(k%2==0) return -1;
    
    int idx=(k+1)/2;
 
     k=1;
    for(int i=1;i<n;i++){
     if(arr[i]!=arr[i-1]) k++;
     if(idx==k) return i;
    }
}