//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        mp[s[i]]++;
        int cnt=0;
        while(true)
        {
            if(mp['b']>=1 && mp['a']>=1 && mp['l']>=2 && mp['o']>=2 && mp['n']>=1)
            cnt++;
            mp['b']--;
            mp['a']--;
            mp['l']-=2;
            mp['o']-=2;
            mp['n']--;
            
            if(mp['b']<1 && mp['a']<1 && mp['l']<2 && mp['o']<2 && mp['n']<1)
            break;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends