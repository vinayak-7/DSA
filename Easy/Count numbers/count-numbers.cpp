//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
bool ThreeCheck(long num)
{
    while(num>0){
            long r = num % 10;
            if (r ==3) {
                return true;
            }
            num /= 10;
        }
        return false;
}
    int count(int N){
        // code here
        long count = 0;
        for(int i = 0;i<=N;i++){
            
            if(ThreeCheck(i)){
                count++;
            }
        }
        long ans = N -count;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends