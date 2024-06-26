//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int arr[4];
        int j = 0;
        
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                int temp = 0;
                while(str[i] >= '0' && str[i] <= '9')
                {
                    temp = (int)temp*10 + (str[i]-'0');
                    i++;
                }
                arr[j++] = temp;
            }
            
        }
        string ans = "";
        if(arr[0]*arr[3] > arr[1]*arr[2])
        {
            return (to_string(arr[0]) + "/" + to_string(arr[1]));
        }
        else if(arr[0]*arr[3] < arr[1]*arr[2])
        {
            return (to_string(arr[2]) + "/" + to_string(arr[3]));
        }
        else
        {
            return "equal";
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends