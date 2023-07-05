//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool isPal(int num)
    {
        int temp = num;
        int rev = 0;
        
        while(num != 0)
        {
            int val = num%10;
            rev = rev*10 + val;
            num = num/10;
        }
        
        if (temp == rev)
        {
            return true;
        }
        
        else{
            return false;
        }
    }
    int PalinArray(int a[], int n)
    {
    	// code here
    	int count = 0;
    	int num = 0;
    	for(int i = 0 ; i < n ; i++)
    	{
    	    num = a[i];
    	    if(isPal(num))
    	    {
    	        count++;
    	    }
    	}
    	
    	if(count == n)
    	{
    	    return true;
    	}
    	
    	else
    	{
    	    return false;
    	}
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends