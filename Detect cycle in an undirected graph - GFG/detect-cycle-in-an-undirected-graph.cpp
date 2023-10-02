//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleBfs(int node, unordered_map<int,bool>&visited, vector<int> adj[])
    {
        unordered_map<int, int>parent;
        parent[node]=-1;
        visited[node]=1;
        
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto it: adj[front]){
                if(visited[it]==true && it!=parent[front]){
                    return true;
                }
                else if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                    parent[it]=front;
                }
            }
        }
        return false;
    }
    
    bool isCycleDfs(int node, int parent, unordered_map<int,bool>&visited, vector<int>adj[])
    {
        visited[node]=true;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                bool cycleFound = isCycleDfs(it, node, visited, adj);
                if(cycleFound)return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // if(isCycleBfs(i, visited, adj)==true)return true;
                if(isCycleDfs(i, -1, visited, adj)==true)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends