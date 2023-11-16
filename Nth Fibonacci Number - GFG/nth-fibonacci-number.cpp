//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007;
class Solution {
  public:
    
    int solve(int n){
        
        int prev1 = 1;
        int prev2 = 0;
        int curr=0;
        
        if(n==0) return prev2;
        
        for(int i=2;i<=n;i++){
            curr = (prev1+prev2)%MOD;
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
  
    int nthFibonacci(int n){
        // code here
        int ans;
        ans = solve(n);
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