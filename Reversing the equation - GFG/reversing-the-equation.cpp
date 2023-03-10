//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<char>st;
            string ans="";
            
            for(int i=s.size()-1;i>=0;i--)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    while(s[i]>='0' && s[i]<='9')
                    {
                        st.push(s[i]);
                        i--;
                    }
                    
                    while(st.size()>0)
                    {
                        ans+=st.top();
                        st.pop();
                    }
                }
                if(!(s[i]>='0' && s[i]<='9'))
                {
                    ans+=s[i];
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends