//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            if(word.size()==0){
                root->isTerminal=true;
                return;
            }

            //Assumption, word will be in small
            int index = word[0]-'a';
            TrieNode* child;

            //present
            if(root->children[index]!=NULL){
                child = root->children[index];
            }else{
                //absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root, word);
        }
        
        void printSuggestions(TrieNode* curr, vector<string>&temp, string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch='a'; ch<='z'; ch++){
                
                TrieNode* next = curr->children[ch-'a'];
                
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        
         vector<vector<string>> getSuggestions(string str){
             TrieNode* prev = root;
             vector<vector<string>> output;
             
             string prefix="";
             int i=0;
             for(i=0;i<str.size();i++){
                 char lastchar = str[i];
                 prefix.push_back(lastchar);
                 
                 TrieNode* curr = prev->children[lastchar-'a'];
                 
                 if(curr==NULL){
                    break;
                 }
              
                vector<string>temp;
                printSuggestions(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;
             }
             
             if(i<str.size()){
                 while(i<str.size()){
                     output.push_back({"0"});
                     i++;
                 }
             }
             return output;
         }
};

class Solution{
public:

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* t = new Trie();
        for(int i=0;i<n;i++){
            t->insertWord(contact[i]);
        }
        
        return t->getSuggestions(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends