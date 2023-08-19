//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int firstOcc(int arr[], int n, int x)
		{
		    int low = 0;
		    int high = n-1;
		    
		    while(low <= high)
		    {
		        int mid = (high + low )/2;
		        if(arr[mid] > x) high = mid-1;
		        else if(arr[mid] < x) low = mid+1;
		        else{
		            if(mid == 0 || arr[mid-1] != arr[mid] ) return mid;
		            else high = mid-1;
		        }
		    }
		    
		    return -1;
		}
		int lastOcc(int arr[], int n, int x)
		{
		    int low = 0;
		    int high = n-1;
		    
		    while(low <= high)
		    {
		        int mid = (high + low )/2;
		        if(arr[mid] > x) high = mid-1;
		        else if(arr[mid] < x) low = mid+1;
		        else{
		            if(mid == n-1 || arr[mid+1] != arr[mid] ) return mid;
		            else low = mid+1;
		        }
		    }
		    
		    return -1;
		}
    	int count(int arr[], int n, int x) {
    	    // code here
    	    int first = firstOcc(arr,n,x);
    	    if(first == -1) return 0;
    	    else return (lastOcc(arr,n,x)-first+1);
    	    
    	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends