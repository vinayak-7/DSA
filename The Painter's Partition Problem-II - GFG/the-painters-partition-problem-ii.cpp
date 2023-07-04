//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int boards[], int n, int k , long long mid){
        long long painterCount = 1;
        long long blockSum = 0;
        
        for(int i = 0 ; i < n ; i++){
            if( blockSum + boards[i] <= mid){
                blockSum += boards[i];
            }
            else
            {
                painterCount++;
                if( painterCount > k || boards[i] > mid){
                    return false;
                }
                blockSum = boards[i];
            }
        }
        return true; 
    }
    long long minTime(int boards[], int n, int k)
    {
        // code here
        // return minimum time
        long long s = 0;
        long long e = 0;
        long long ans = -1;
        
        for(int i=0 ; i < n ; i++){
            e+= boards[i];
        }
        long long mid = s+(e-s)/2;
        while(s<=e){
            if(isPossible(boards,n,k,mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s+(e-s)/2;
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends