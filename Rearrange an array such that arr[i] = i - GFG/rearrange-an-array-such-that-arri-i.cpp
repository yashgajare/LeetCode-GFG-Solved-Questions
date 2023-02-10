//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
        int * modifyArray(int arr[], int n){
        
        // Complete the function
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)!=mp.end())
            arr[i]=i;
            else
            arr[i]=-1;
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        Solution ob;
        int *b;
        b = ob.modifyArray(a, n);
        for(int i=0;i<n;i++)
            cout << b[i] << " ";
        
        cout << endl;
        
    }
    
    return 0;
}

// } Driver Code Ends