//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    bool isHappy(int hppy){
        if(hppy==1 || hppy==7) return 1;
        
        int sum,b=hppy;
        
        while(b>9){
            sum=0;
            while(b!=0){
                int last=b%10;
                sum+=last*last;
                b/=10;
            }
            
            if(sum==1 || sum==7) return 1;
            
            b=sum;
        }
        return 0;
    }
    
    int nextHappy(int num){
        int hppy=num+1;
        while(isHappy(hppy)!=1) hppy++;
        
        return hppy;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends