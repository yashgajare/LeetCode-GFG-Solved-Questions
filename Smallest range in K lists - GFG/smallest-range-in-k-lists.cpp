//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

class node{
    public:
        int data;
        int row;
        int col;
        
        node(int data, int row, int col){
            this->data=data;
            this->row=row;
            this->col=col;
        }
};

class compare{
    
    public:
        bool operator()(node* &a, node* &b){
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<node*, vector<node*>, compare> pq;
        int mini = INT_MAX, maxi=INT_MIN;
        
        for(int i=0; i<k; i++){
            int ele = arr[i][0];
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            pq.push(new node(ele,i,0));
        }
        
        int start=mini, end=maxi;
        
        while(!pq.empty()){
            node* top = pq.top();
            pq.pop();
            
            mini = top->data;
            
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            
            if(top->col+1 < n){
                maxi = max(maxi, arr[top->row][top->col+1]);
                pq.push(new node(arr[top->row][top->col+1], top->row, top->col+1));
            }
            else{
                break;
            }
        }
        
        pair<int,int>p = make_pair(start, end);
        return p;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends