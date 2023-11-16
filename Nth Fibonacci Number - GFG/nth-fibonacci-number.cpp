//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007;
class Solution {
  public:
    
    int solve(int n, int dp[]){
        if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = (solve(n-1, dp) + solve(n-2, dp))%MOD;
        
        return dp[n];
    }
  
    int nthFibonacci(int n){
        // code here
        int dp[n+1];
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        int ans;
        ans = solve(n, dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends