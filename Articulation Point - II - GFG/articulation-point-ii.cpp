//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int node, int &parent, int &timer, vector<int>&disc, vector<int>&low, 
    unordered_map<int, bool> &vis, vector<int>&ans, vector<int>adj[])
    {
        vis[node]=1;
        low[node]=disc[node]=timer++;
        int child=0;
        
        for(auto nbr: adj[node])
        {
            if(nbr==parent) continue;
            
            if(!vis[nbr])
            {
                dfs(nbr, node, timer, disc, low, vis, ans, adj);
                low[node] = min(low[node], low[nbr]);
                
                if(low[nbr]>=disc[node] && parent!=-1)
                ans[node]=1;
                
                child++;
            }
            else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
        
        if(parent==-1 && child>1) ans[node]=1;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
            
        vector<int>disc(V, -1);
        vector<int>low(V, -1);
        unordered_map<int, bool>vis;
        int parent=-1;
        int timer=0;
        vector<int>ans(V, 0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, parent, timer, disc, low, vis, ans, adj);
            }
        }
        
        vector<int>res;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0) res.push_back(i);
        }
        
        if(res.empty()) return {-1};
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends