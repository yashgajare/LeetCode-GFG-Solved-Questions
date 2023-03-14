//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.size()%2==1)
    return -1;
    stack<char>st;
    int cnt=0;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')
        st.push(s[i]);
        else
        {
            if(st.size()==0)
            {
                cnt++;
                st.push('{');
            }
            else
            st.pop();
        }
    }
    
    cnt+=st.size()/2;
    return cnt;
}