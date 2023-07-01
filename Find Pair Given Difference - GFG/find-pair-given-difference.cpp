//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int target){
    //code
	sort(arr,arr+n);
	int i = 0 , j = 0;
    while(j < n)
    {
        if(arr[j] - arr[i] == target && i != j) return true;
        else if(arr[j] - arr[i] < target) j++;
        else i++;
    }

    return false;
}