//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    priority_queue<int>mn;
    priority_queue<int, vector<int>, greater<int> >mx;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(mn.size()==0){
            mn.push(x);
            return;
        }
        
        if(mn.size() > mx.size()){
            if(x < mn.top()){
                mx.push(mn.top());
                mn.pop();
                mn.push(x);
            }
            else{
                mx.push(x);
            }
        }
        else{
            if(x < mn.top()){
                mn.push(x);
            }
            else{
                mx.push(x);
                mn.push(mx.top());
                mx.pop();
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(mx.size() == mn.size())
        return (double) (mx.top()+mn.top())/2.0;
        else
        return (double) mn.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends