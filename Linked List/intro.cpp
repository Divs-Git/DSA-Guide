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
  int cnt = 0;
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
    cnt++;
  }
  cout <<"END" <<endl; 
  cout <<cnt <<endl;
}

int main() {
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  first->next = second;
  second->next = third;
  Node* head = first;
  printLL(head);
}