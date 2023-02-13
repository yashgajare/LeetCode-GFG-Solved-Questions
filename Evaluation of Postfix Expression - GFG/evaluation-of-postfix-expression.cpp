//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        int n=S.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(S[i]>='0' && S[i]<='9')
            s.push(S[i]-'0');
            else
            {
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                
                if(S[i]=='+')
                {
                    int res = op2+op1;
                    s.push(res);
                }
                else if(S[i]=='-')
                {
                    int res=op2-op1;
                    s.push(res);
                }
                else if(S[i]=='*')
                {
                    int res=op2*op1;
                    s.push(res);
                }
                else if(S[i]=='/')
                {
                    int res=op2/op1;
                    s.push(res);
                }
                
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends