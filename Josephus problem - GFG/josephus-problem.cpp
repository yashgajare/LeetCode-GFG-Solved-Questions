//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    
    void solve(vector<int>v, int k, int index, int &ans)
    {
        if(v.size()==1)
        {
            ans=v[0];
            return;
        }
        
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        
        solve(v,k,index,ans);
        
        return;
    }
    
    public:
    int josephus(int n, int k)
    {
       //Your code here
       vector<int>v;
       for(int i=0;i<n;i++)
       {
           v.push_back(i+1);
       }
       k=k-1;
       int index=0;
       int ans=-1;
       
       solve(v, k, index, ans);
       
       return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends