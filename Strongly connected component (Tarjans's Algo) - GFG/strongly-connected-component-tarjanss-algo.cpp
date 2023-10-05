//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    
    int timer=0;
    
	void dfs(int node, vector<int> &disc, vector<int> &low, stack<int>&s,
	vector<bool> &instack, vector<vector<int> >&res, vector<bool> &vis, vector<int> adj[])
	{
	    vis[node]=true;
	    disc[node] = low[node] = timer++;
	    s.push(node);
	    instack[node]=true;
	    
	    for(int nbr: adj[node])
	    {
	        // if neighbour is not visited
	        if(!vis[nbr]){
	            dfs(nbr, disc, low, s, instack, res, vis, adj); //call dfs
	            low[node] = min(low[node], low[nbr]); // update low
	        }
	        // if neighbour is visited and present in vector instack 
	        // Differentiate back edge and cross edge
	        else if(instack[nbr]){  //back edge
	            low[node] = min(low[node], disc[nbr]); // update low of node
	        }
	    }
	    // if node is head node of scc
	    if(disc[node] == low[node])
	    {
	        vector<int>ans;
	        while(s.top()!=node)
	        {
	            ans.push_back(s.top());
	            instack[s.top()]=false;
	            s.pop();
	        }
	        ans.push_back(s.top());
	        instack[s.top()]=false;
	        s.pop();
	        sort(ans.begin(), ans.end());
	        res.push_back(ans);
	    }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int>disc(V, -1);
        vector<int>low(V, -1);
        stack<int>s;
        vector<bool>inStack(V, false);
        vector<vector<int>> res;
        vector<bool>vis(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, disc, low, s, inStack, res, vis, adj);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends