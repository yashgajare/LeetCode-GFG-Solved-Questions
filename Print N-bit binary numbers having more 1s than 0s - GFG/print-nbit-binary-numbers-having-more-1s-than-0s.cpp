//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
    vector<string>v;
    void solve(int one, int zero, int N, string op)
    {
        if(N==0)
        {
            v.push_back(op);
            return;
        }
        
        string op1=op;
        op1.push_back('1');
        solve(one+1,zero,N-1,op1);
            
        if(one>zero)
        {
            string op2=op;
            op2.push_back('0');
            solve(one,zero+1,N-1,op2);
        }
        return;
    }
    
public:	
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    string op="";
	    int one=0;
	    int zero=0;
	    solve(one,zero,N,op);
	    
	    return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends