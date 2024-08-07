// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverseLL(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        int carry = 1;
        head = reverseLL(head);
        Node* temp = head;
        while(temp->next != NULL) {
            int totalSum = temp->data + carry;
            int digit = totalSum%10;
            carry = totalSum/10;
            temp->data = digit;
            
            if(carry == 0)break;
            temp = temp->next;
        }
        
        if(carry != 0) {
            int totalSum = temp->data + carry;
            int digit = totalSum%10;
             carry = totalSum/10;
            temp->data = digit;
            if(carry != 0) {
            Node* newNode = new Node(carry);
            temp->next = newNode;
            }
        }
        // return head of list after adding one
        head = reverseLL(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends