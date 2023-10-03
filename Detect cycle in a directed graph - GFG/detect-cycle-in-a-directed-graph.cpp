//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // find indegree
        vector<int>indegree(V);
        for(int i=0;i<V;i++){
            for(auto j: adj[i]) indegree[j]++;
        }
        
        // inserting nodes in queue having indegree=0
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        // bfs
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
          
        //checking indegree of all nodes is zero
        for(int i=0; i<V; i++){
            if(indegree[i]!=0) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends