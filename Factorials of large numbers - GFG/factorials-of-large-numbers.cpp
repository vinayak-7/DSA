//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int> arr;
        arr.push_back(1);
        
        for(int x = 2 ; x <= n ; x++)
        {
            int cry = 0;
            for(int i = 0 ; i < arr.size() ; i++)
            {
                int val = arr[i]*x + cry;
                arr[i] = val%10;
                cry = val/10;
            }
            
            while(cry!=0)
            {
                arr.push_back(cry%10);
                cry/=10;
            }
        }
        reverse(arr.begin(),arr.end());
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends