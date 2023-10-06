//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>dist(n+1, INT_MAX);
        vector<int>parent(n+1);
        set<pair<int, int>>s;
        int src=1;
        dist[src]=0;
        // parent[src]=-1;
        for(int i=1; i<n+1; i++) parent[i]=i;
        s.insert({0, src});
        
        while(!s.empty())
        {
            auto top = *(s.begin());
            int nodeDist = top.first;
            int node = top.second;
            s.erase(s.begin());
            
            for(auto nbr:adj[node])
            {
                int u = nbr.first;
                int wt = nbr.second;
                
                if(nodeDist + wt < dist[u])
                {
                    auto record = s.find(make_pair(dist[u], u));
                    if(record!=s.end()){
                        s.erase(record);
                    }
                    dist[u] = nodeDist+wt;
                    parent[u]=node;
                    s.insert({dist[u], u});
                }
            }
        }
        
        int curr = n;
        if(dist[curr]==INT_MAX) return {-1};
        
        vector<int>ans;
        while(parent[curr]!=curr)
        {
            ans.push_back(curr);
            curr = parent[curr];
        }
        
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends