#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

  Node() {
    this->next = NULL;
    this->prev = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
    }
};

void printLL(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout <<"END" <<endl; 
}

int getLength(Node* head) {
  int cnt = 0;
  Node* temp = head;
  while(temp !=NULL) {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}

void insertAtHead(Node* &head,Node* &tail,int value) {
  Node* curr = head;
  Node* node = new Node(value);
  
  if(head == NULL) {
    head = node;
    tail = node;
    return;
  }
  
  head->prev = node;
  node->next = head;
  head = node;
  
}

void insertAtTail(Node* &head,Node* &tail,int value) {
  Node* newNode = new Node(value);
  if(head == NULL) {
    head = newNode;
    tail = newNode;
  }
  
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

void insertAtMiddle(Node* &head,Node* &tail,int value,int pos) {
  Node* newNode = new Node(value);
  int len = getLength(head);
  if(head == NULL) {
    head = newNode;
    tail = newNode;
    return;
  }
  
  if(pos == 1) {
    insertAtHead(head,tail,value);
    return;
  } else if(pos >= len + 1) {
    insertAtTail(head,tail,value);
    return;
  } else {
    Node* curr = head;
    Node* prev = NULL;
    while(pos != 1) {
      pos--;
      prev = curr;
      curr = curr->next;
    }
    
    prev->next = newNode;
    curr->prev = newNode;
    newNode->next = curr;
    newNode->prev = prev;

  }
}

void deletion(Node* &head,Node* &tail,int pos) {
  int len = getLength(head);
  if(head == NULL) {
    cout<<"Can't delete" <<endl;
    return;
  }
  
  if(head == tail) {
    Node* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
  }
  
  if(pos == 1) {
    // head deletion
    Node* temp  = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return;
  } else if(pos == len) {
    // tail deletion
    Node* prevNode = tail->prev;
    tail->prev = NULL;
    prevNode->next = NULL;
    delete tail;
    tail = prevNode;
    return;
  } else {
    Node* curr = head;
    Node* prevNode = NULL;
    while(pos != 1) {
      pos--;
      prevNode = curr;
      curr = curr->next;
    }
    
    Node* nextNode = curr->next;
    
    prevNode->next = nextNode;
    curr->next = NULL;
    curr->prev = NULL;
    nextNode->prev = prevNode;
    delete curr;
  }
}
 

int main() {
  Node* head = NULL;
  Node* tail = NULL;
  printLL(head);
  insertAtHead(head,tail,40);
  insertAtHead(head,tail,30);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,10);
  insertAtTail(head,tail,50);
  insertAtMiddle(head,tail,10,6);
  deletion(head,tail,4);
  printLL(head);
}