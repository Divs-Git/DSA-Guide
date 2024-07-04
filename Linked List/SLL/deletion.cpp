#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

  Node() {
    this->next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
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

void deletion(Node* &head,Node* &tail,int pos) {
  if(head == NULL) {
    cout <<"No element to delete";
    return;
  }
  
  if(head == tail) {
    Node* temp = head;
    delete temp;
    head = NULL;
    temp = NULL;
  }
  
  int len = getLength(head);
  
  if(pos == 1) {
    Node* temp = head;
    head= head->next;
    delete temp;
  } else if(pos == len) {
    Node* prev = head;
    while(prev->next != tail) {
      prev = prev->next;
    }
    prev->next = NULL;
    delete tail;
    tail = prev;
  } else {
    Node* prev = NULL;
    Node* curr = head;
    while(pos != 1) {
      pos--;
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

int main() {
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  first->next = second;
  second->next = third;
  Node* head = first;
  Node* tail = third;
  printLL(head);
  deletion(head,tail,2);
  printLL(head);
}