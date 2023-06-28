//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int firstOcc(vector<int> &arr, int n , int x){
        int low = 0;
        int high = n-1;
        int ans = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == x) 
            {
                high = mid-1;
                ans = mid;
            }
            else if(arr[mid]<x) low = mid+1;
            else high = mid - 1;
        }
        return ans;
    }
    int lastOcc(vector<int> &arr, int n , int x){
        int start = 0;
        int end = n-1;
        int ans = -1;
        int m = (start+end)/2;
        while(start<=end){
            m = (start+end)/2;
            if(arr[m]==x) 
            {
                ans = m;
                start = m+1;
            }
            else if(arr[m]>x) end = m-1;
            else start = m + 1;
        }
        return ans;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int first = firstOcc(arr,n,x);
        int last = lastOcc(arr,n,x);
        if(first == -1 || last == -1) return {-1};
        return {first,last};
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends