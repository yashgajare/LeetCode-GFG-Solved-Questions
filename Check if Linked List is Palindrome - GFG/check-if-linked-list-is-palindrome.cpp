//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* forw;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    
    Node* getMid(Node* slow, Node* fast){
         while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        //1 2 3 3 2 1
        Node* slow=head;
        Node* fast=head->next;
        Node* mid=getMid(slow,fast);
        Node* tmp=mid->next;
        mid->next=reverse(tmp);
        Node* head1=head;
        Node* head2=mid->next;
        while(head2!=NULL){
            if(head1->data!=head2->data) return false;
            head1=head1->next;
            head2=head2->next;
        }
        tmp=mid->next;
        mid->next=reverse(mid->next);
        return true;
        
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends