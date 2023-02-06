//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int>p;
	    vector<int>ng;
	    vector<int>ans;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        p.push_back(arr[i]);
	        else
	        ng.push_back(arr[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(p.size()!=0){
	        ans.push_back(p[i]);
	        p.pop_back();
	        }
	        if(ng.size()!=0){
	        ans.push_back(ng[i]);
	        ng.pop_back();
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    arr[i]=ans[i];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends