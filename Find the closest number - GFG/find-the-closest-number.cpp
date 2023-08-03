//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
        // Complete the function
        int ans = -1;
        int diff = INT_MAX;
        int low = 0;
        int high = n-1;
        int lastInd = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == target) {
                return arr[mid];
            }else if(arr[mid] > target) {
                high = mid-1;
                if(abs(arr[mid]-target) <= diff) {
                    if(mid > lastInd) {
                        lastInd = mid;
                    }
                    diff = abs(arr[mid]-target);
                    ans = arr[mid];
                }
            }else if(arr[mid] < target) {
                low = mid+1;
                if(abs(arr[mid]-target) < diff) {
                    if(mid > lastInd) {
                        lastInd = mid;
                    }
                    diff = abs(arr[mid]-target);
                    ans = arr[mid];
                }
            }
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
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends