//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    int solve(int n, int dp[]){
	        if(n<=1 ) return 1;
	        
	        if(dp[n]!=-1) return dp[n];
	        
	        dp[n] = 1 + min(solve(n-1, dp),solve(n-2, dp));
	        
	        return dp[n];
	    }
	 
		int nthStair(int n){
		    //  Code here
		    int dp[n+1];
		    for(int i=0;i<=n;i++) dp[i]=-1;
		    int ans = solve(n, dp);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends