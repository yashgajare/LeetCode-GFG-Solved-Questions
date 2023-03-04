//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}

// } Driver Code Ends



bool saveIronman(string ch)
{
    // Complete the function
    string str;
    for(int i=0;i<ch.size();i++)
    {
        if( ch[i]>=48 && ch[i]<=57 || ch[i]>=65 && ch[i]<=90 || ch[i]>=97 && ch[i]<=122 )
        {
            str+=ch[i];
        }
    }
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int flag=0;
    int s=0,e=str.size()-1;
    
    while(s<=e)
    {
        if(str[s]==str[e])
        {
            s++;
            e--;
            flag=1;
        }
        else
        {
            
            flag=0;
            break;
        }
    }
    if(flag==1)
    return 1;
    else 
    return 0;
}
