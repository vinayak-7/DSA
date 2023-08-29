//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int>sum;
        int currentsum=0;
        for(int i=0;i<N;i++)
        {
            currentsum =0;
            for(int j=i;j<N;j++)
            {
                currentsum+=Arr[j];
                sum.push_back(currentsum);
            }
        }
        sort(sum.begin(), sum.end(), greater<int>());
        return sum[K-1];
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends