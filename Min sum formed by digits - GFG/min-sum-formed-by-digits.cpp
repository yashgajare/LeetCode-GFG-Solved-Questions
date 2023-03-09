//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        long long int lnum=0;
        long long int rnum=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            lnum=lnum*10+arr[i];
            else
            rnum=rnum*10+arr[i];
        }
        return lnum+rnum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends