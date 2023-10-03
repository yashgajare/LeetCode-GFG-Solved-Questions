//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int>dist(V, INT_MAX);
        set<pair<int, int>>st;
        
        dist[s]=0;
        st.insert(make_pair(0,s)); 
        
        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDist = top.first;
            int node = top.second;
            
            st.erase(st.begin());
            
            for(auto it: adj[node]){
                if(nodeDist + it[1] < dist[it[0]]){
                    auto record = st.find(make_pair(dist[it[0]], it[0]));
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    dist[it[0]] = nodeDist+it[1];
                    st.insert(make_pair(dist[it[0]], it[0]));
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends