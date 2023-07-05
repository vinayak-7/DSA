//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string printSequence(string str)
{
    //code here.
    string ans = "";
    unordered_map<char, string> keypad = {
        {'A', "2"}, {'B', "22"}, {'C', "222"},
        {'D', "3"}, {'E', "33"}, {'F', "333"},
        {'G', "4"}, {'H', "44"}, {'I', "444"},
        {'J', "5"}, {'K', "55"}, {'L', "555"},
        {'M', "6"}, {'N', "66"}, {'O', "666"},
        {'P', "7"}, {'Q', "77"}, {'R', "777"}, {'S', "7777"},
        {'T', "8"}, {'U', "88"}, {'V', "888"},
        {'W', "9"}, {'X', "99"}, {'Y', "999"}, {'Z', "9999"},
        {' ', "0"}
    };
    for(char c : str)
    {
        ans += keypad[toupper(c)];
    }
    
    return ans;
}