//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	// finding linear ordering through topological sort
	void dfs(int node, stack<int> &s, unordered_map<int, bool> &vis, vector<vector<int>> &adj)
	{
	    vis[node]=true;
	    
	    for(auto nbr: adj[node]){
	        if(!vis[nbr]){
	            dfs(nbr, s, vis, adj);
	        }
	    }
	    s.push(node);
	}
	
	void revDfs(int node, unordered_map<int, bool> &vis, vector<vector<int>> &adjT)
	{
	    vis[node]=true;
	    
	    for(auto nbr: adjT[node]){
	        if(!vis[nbr]){
	            revDfs(nbr, vis, adjT);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        unordered_map<int, bool>vis;
        stack<int>s;
        
        for(int i=0; i<V;i++){
            if(!vis[i]){
                dfs(i, s, vis, adj);
            }
        }
        
        // creating a transpose graph
        vector<vector<int>> adjT(V);
        for(int i=0; i<V;i++){
            vis[i]=false;
            for(auto nbr: adj[i]){
                adjT[nbr].push_back(i);
            }
        }
        
        // dfs call using above ordering
        int cnt=0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
        
            if(!vis[top]){
                cnt++;
                revDfs(top, vis, adjT);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends