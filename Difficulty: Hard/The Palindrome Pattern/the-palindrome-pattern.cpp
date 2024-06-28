//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool checkPalindrome(string temp)
    {
        int i = 0;
        int j = temp.size()-1;
        while(i < j)
        {
            if((temp[i]) != (temp[j]))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
            
        }
        return true;
    }

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        for(int i = 0 ; i < arr.size() ; i++)
        {
            string temp = "";
            for(int j = 0 ; j < arr.size() ; j++)
            {
                temp += arr[i][j];
            }
            if(checkPalindrome(temp))
            {
                string ans = "";
                ans = to_string(i)+ " R";
                return ans;
            }
        }
        for(int i = 0 ; i < arr.size() ; i++)
        {
            string temp = "";
            for(int j = 0 ; j < arr.size() ; j++)
            {
                temp += arr[j][i];
            }
            if(checkPalindrome(temp))
            {
                string ans = "";
                ans = to_string(i)+ " C";
                return ans;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends