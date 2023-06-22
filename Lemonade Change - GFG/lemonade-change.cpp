//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int remain=0;
        int b5=0,b10=0,b20=0;
        if(bills[0]>5)
        return false;
        for(int i=0;i<N;i++){
            if(bills[i]==5) b5+=1;
            else if(bills[i]==10) {
                b10++;
               if(b5>0){
                   b5-=1;
               }
               else return false;
            }
            else{
                b20++;
                if(b5>0 &&  b10>0){
                    b5--;
                    b10--;
                }
                else if(b5>2)
                b5-=3;
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends