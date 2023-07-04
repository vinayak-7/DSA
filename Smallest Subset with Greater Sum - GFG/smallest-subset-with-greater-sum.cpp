//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> nums,int n){
        int cnt = 0;
        long long int sum = 0;
        long long int val = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i];
        }
        
        while(sum >= val)
        {
            cnt++;
            val += nums[n-cnt];
            sum -= nums[n-cnt];
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends