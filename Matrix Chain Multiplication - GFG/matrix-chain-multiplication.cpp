// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int l, int r, int* arr, vector<vector<int>>&dp){
        if(l==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        dp[l][r] = 1e9;
        for(int k=l ; k<r ; k++){
            dp[l][r] = min(dp[l][r], solve(l, k, arr, dp) + solve(k+1, r, arr, dp) + arr[l-1]*arr[k]*arr[r]);
        }
        return dp[l][r];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        return solve(1, N-1, arr, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends