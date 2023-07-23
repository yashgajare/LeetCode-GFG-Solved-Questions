//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    void inserttail(struct Node* &head, struct Node* &tail, int val){
        struct Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry=0;
        struct Node* reshead=NULL;
        struct Node* restail=NULL;
        while(first!=NULL || second!=NULL || carry!=0){
            int sum=0,val1=0,val2=0;
            if(first!=NULL){
                val1=first->data;
                first=first->next;
            }
            if(second!=NULL){
               val2=second->data;
                second=second->next;
            }
            sum=val1+val2+carry;
            int digit=sum%10;
            carry=sum/10;
            inserttail(reshead,restail,digit);
        }
        return reshead;
    }
    
    struct Node* reverse(struct Node* head){
        struct Node* prev=NULL;
        struct Node* curr=head;
        struct Node* forw;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        
        Node* res = add(first,second);
        res= reverse(res);
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends