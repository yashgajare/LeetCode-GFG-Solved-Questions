//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){
        
        queue<long long int>q;
        vector<long long int>v;
        
        for(int i=0;i<K;i++)
        {
            if(A[i]<0)
            q.push(A[i]);
        }
        
        if(q.size()==0)
        v.push_back(0);
        else
        v.push_back(q.front());

        long long int j=K;
        long long int i=0;
        while(j<N)
        {
            if(q.size()>0 && A[i]==q.front())
            q.pop();
            i++;
            
            if(A[j]<0)
            q.push(A[j]);
            
            j++;
            
            if(q.size()>0)
            v.push_back(q.front());
            else
            v.push_back(0);
        }
        
        return v;

 }