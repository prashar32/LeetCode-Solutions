// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   int ans = 0;
	   vector<pair<int,int>>dp(n+1, {0, 0});
	   for(int i=1 ; i<=n ; i++){
	       dp[i] = make_pair(arr[i-1], arr[i-1]);
	       for(int j=i-1 ; j>=0 ; j--){
	           if(dp[j].second < arr[i-1] && arr[i-1] + dp[j].first > dp[i].first){
	               dp[i].first = arr[i-1] + dp[j].first;
	           }
	       }
	       ans = max(ans, dp[i].first);
	   }
	   return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends