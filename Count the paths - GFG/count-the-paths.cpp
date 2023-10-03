//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int s, int d, int &cnt, vector<int>adj[]){
        if(s==d){
            cnt++;
        }

        for(auto it: adj[s]){

            dfs(it, d, cnt, adj);
        }
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){

	    int cnt=0;
	    vector<int>adj[n];
	    for(auto e: edges){
	        int u = e[0];
	        int v = e[1];
	        adj[u].push_back(v);
	    }
	    
	    dfs(s,d,cnt, adj);
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends