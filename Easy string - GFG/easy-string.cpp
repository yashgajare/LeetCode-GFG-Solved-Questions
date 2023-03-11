//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string s){
    //complete the function here
    transform(s.begin(),s.end(),s.begin(), :: tolower);
    string ans="";
    
    int cnt=1;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==s[i+1])
        cnt++;
        else
        {
            ans+=to_string(cnt);
            ans+=s[i];
            cnt=1;
        }
    }
    return ans;
}

