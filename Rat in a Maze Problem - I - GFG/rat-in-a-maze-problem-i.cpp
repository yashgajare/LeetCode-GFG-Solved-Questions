//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    bool isSafe(int x, int y, vector<vector<int>> &m, vector<vector<int>> visited, int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1)) return true;
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, vector<vector<int>> visited, vector<string> &ans, int x, int y, string path){
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=1;
        
        
        //down
        int nx=x+1;
        int ny=y;
        if(isSafe(nx,ny,m,visited,n)){
            path.push_back('D');
            solve(m,n,visited,ans,nx,ny,path);
            path.pop_back();
        }
        
        //up
        nx=x-1;
        ny=y;
        if(isSafe(nx,ny,m,visited,n)){
            path.push_back('U');
            solve(m,n,visited,ans,nx,ny,path);
            path.pop_back();
        }
        
        //left
        nx=x;
        ny=y-1;
        if(isSafe(nx,ny,m,visited,n)){
            path.push_back('L');
            solve(m,n,visited,ans,nx,ny,path);
            path.pop_back();
        }
        
        //right
        nx=x;
        ny=y+1;
        if(isSafe(nx,ny,m,visited,n)){
            path.push_back('R');
            solve(m,n,visited,ans,nx,ny,path);
            path.pop_back();
        }
        
        visited[x][y]=0;
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        
        if(m[0][0]==0)
        return ans;
        
        vector<vector<int>>visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            visited[i][j]=0;
        }
        string path="";
        int srcx=0,srcy=0;
        
        solve(m,n,visited,ans,srcx,srcy,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends