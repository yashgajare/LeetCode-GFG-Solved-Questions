//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	if(N<=0)
	return {};
	
	queue<string>q;
	q.push("1");
	vector<string>ans;
	int cnt=0;
	while(cnt<N)
	{
	    string t=q.front();
	    ans.push_back(t);
	    q.pop();
	    q.push(t+"0");
	    q.push(t+"1");
	    cnt++;
	}
	return ans;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends