//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct line{
    int a,b,c;
    line(int x,int y,int c){
        a=x;
        b=y;
        this->c=c;
    }
};
struct point{
    int x,y;
    point(){}
    point(int a,int b){
        x=a;
        y=b;
    }
};
class Solution{
    public:
    double EPS=1e-8;
    double sq(double x){
        return x*1.0*x;
    }
    double dist(point p,double x,double y){
        return sqrt(sq(x-p.x)+sq(y-p.y));
    }
    double compute(point p[], int n, line l, double X)
{
    double res = 0;
    double Y = -1 * (l.c + l.a * X) / l.b;
    for (int i = 0; i < n; i++)
        res += dist(p[i],X,Y);
 
    return res;
}
double find(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;
    while ((high - low) > EPS) {
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
 
        //
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);
 
        if (dist1 < dist2)
            high = mid2;
 
        else
            low = mid1;
    }
 
    return compute(p, n, l, (low + high) / 2);
}
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
         point pn[n];
         line li=line(get<0>(l),get<1>(l),get<2>(l));
 
    for (int i = 0; i < n; i++)
        pn[i] = point(p[i].first, p[i].second);
 
    return find(pn,n,li);
	    
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends