#include<bits/stdc++.h>
using namespace std;

// 1. Using arrays -> does not dynamically change
struct MyStack {
  int *arr;
  int cap;
  int top;

  MyStack(int c) {
    cap = c;
    arr = new int[cap]; 
    top = -1;
  }

  void push(int data) {
    if(top == cap - 1) {
      cout <<"Stack Overflow" <<endl;
      return;
    }
     top++;
    arr[top] = data;
  }

  int pop() {
    if(top == -1) {
      cout <<"Stack Underflow" <<endl;
      return -1;
    }
    int res = arr[top];
    top--;
    return res;
  }

  int peek() {
    if(top == -1) {
      cout <<"Stack Underflow" <<endl;
      return -1;
    }
    return arr[top];
  }

  int size() {
    return top+1;
  }

  bool isEmpty() {
    return top == -1;
  }

};


int main() {
  MyStack st(5);
  st.push(3);
  st.push(32);
  st.push(324);
  st.push(4);
  st.push(43);

  cout <<st.pop() <<endl;
  cout <<st.peek() <<endl;
  cout <<st.size() <<endl;
  cout <<st.isEmpty() <<endl;
  
  return 0;
}