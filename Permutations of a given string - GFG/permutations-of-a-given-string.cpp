//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void solve(string S, vector<string>&ans, int idx){
        if(idx>=S.size()){
        ans.push_back(S);
        return;
        }
        
        for(int j=idx;j<S.size();j++){
            swap(S[idx],S[j]);
            solve(S,ans,idx+1);
             swap(S[idx],S[j]);
        }
    }
    
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    int idx=0;
		    solve(S,ans,idx);
		    set<string>st;
		    for(int i=0;i<ans.size();i++)
		    st.insert(ans[i]);
		    ans.clear();
		    for(auto it: st)
		    ans.push_back(it);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends