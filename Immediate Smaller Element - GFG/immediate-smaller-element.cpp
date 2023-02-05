//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    vector<int>v;
	    stack<int>s;
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        if(s.size()==0)
	        v.push_back(-1);
	        
	        else if(s.size()>0 && s.top()<arr[i])
	        v.push_back(s.top());
	        
	        else if(s.size()>0 && s.top()>=arr[i])
	        v.push_back(-1);
	        
	        s.push(arr[i]);
	    }
	    reverse(v.begin(),v.end());
	    for(int i=0;i<n;i++)
	    arr[i]=v[i];
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends