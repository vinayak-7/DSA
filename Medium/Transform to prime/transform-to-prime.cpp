//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isPrime(int n)
    {
        for(int i = sqrt(n) ; i > 1 ; i--)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        int sum = 0;
        for(int i = 0 ; i  < N ; i++) sum += arr[i];
        
        
        int temp = sum;
        if(temp % 2 == 0) temp++;
        
        while(!isPrime(temp))
        {
            temp += 2;
        }
        return temp - sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends