//{ Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}


// } Driver Code Ends


int binarySearch(int s , int * input , int l , int tar){
    while(l-s > 1){
        int mid = (s+l) >> 1 ; 
        if(tar < input[mid]) l = mid - 1 ; 
        else if(tar >= input[mid]) s = mid ; 
    }
    if(input[l] == tar) return l ; 
    if(input[s] == tar) return s ;
    return -1 ; 
}

long long int calculate(int * input, int n){
    sort(input , input+n) ; long long ans = 0 ; 
    for(int i = 0 ; i < n ; i ++){
        int lastOcc = i+1 != n ? binarySearch(i+1,input,n-1,input[i]) : -1 ; 
        if(lastOcc == -1) continue ; 
        ans = ans + (lastOcc - i) ; 
    }
   return ans;
}
