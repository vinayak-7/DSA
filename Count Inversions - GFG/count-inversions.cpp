//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long l, long long m, long long r, long long &ctr)
    {
        long long i = l, j = m+1, k = l , tmp[r];
        while( i <= m && j <=r )
        {
            if(arr[i] <= arr[j]) tmp[k] = arr[i], i++ , k++;
            else ctr = ctr+ (m-i+1), tmp[k] = arr[j], j++ , k++;
        }
        while( i <= m) tmp[k] = arr[i] , i++, k++;
        while( j <= r) tmp[k] = arr[j] , j++, k++;
        for(int i = l; i <= r; i++) arr[i] = tmp[i];
    }
    
    void mergeSort(long long arr[], long long l, long long r, long long &ctr)
    {
        if(l<r)
        {
            long long mid = (l+r)/2;
            mergeSort(arr,l,mid,ctr);
            mergeSort(arr,mid+1,r,ctr);
            merge(arr,l,mid,r,ctr);
        }
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long ctr = 0;
        mergeSort(arr,0,n-1,ctr);
        return ctr;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends