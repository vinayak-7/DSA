//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	private:
	int getSum(int X[], int n)
	{
	    int sum = 0;
	    for (int i = 0; i < n; i++)
	        sum += X[i];
	    return sum;
	}
	 

	int getTarget(int A[], int n, int B[], int m)
	{

	    int sum1 = getSum(A, n);
	    int sum2 = getSum(B, m);
	 

	    if ((sum1 - sum2) % 2 != 0)
	        return INT_MIN;
	    return ((sum1 - sum2) / 2);
	}

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{

	    sort(A, A + n);
	    sort(B, B + m);
	 

	    int target = getTarget(A, n, B, m);
	 
	    if (target == INT_MIN)
	        return -1;
	 
	    int i = 0, j = 0;
	    while (i < n && j < m) 
	    {
	        int diff = A[i] - B[j];
	        if (diff == target) 
	        {
	            return 1;
	        }

	        else if (diff < target)
	            i++;

	        else
	            j++;
	    }
	    
	    return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends