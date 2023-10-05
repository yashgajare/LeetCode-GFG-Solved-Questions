//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,1e8);
	    int src=0;
	    dist[src]=0;
	    
	    for(int i=0; i<n-1; i++){
	        for(int j=0;j<edges.size();j++){
	            int u = edges[j][0];
    	        int v = edges[j][1];
    	        int w = edges[j][2];
	        
	            if((dist[u]+w)<dist[v])
	            dist[v] = dist[u] + w;
	        }
	    }
	    
	    bool flag = false;
	    
	    for(int j=0;j<edges.size();j++)
	    {
	        int u = edges[j][0];
            int v = edges[j][1];
    	    int w = edges[j][2];
	        
            if((dist[u]+w)<dist[v])
	            flag=true;
	    }
	    
	    if(flag==false) return 0;
	    return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends