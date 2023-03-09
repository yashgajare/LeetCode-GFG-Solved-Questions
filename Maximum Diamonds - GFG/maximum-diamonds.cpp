//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int maxDiamonds(int A[], int N, int K) {
        // code here
        int sum=0;
        priority_queue<int>pq;
        for(int i=0;i<N;i++)
        pq.push(A[i]);
        
        while(K>0)
        {
            int val=pq.top();
            sum+=val;
            pq.pop();
            pq.push(val/2);
            K--;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends