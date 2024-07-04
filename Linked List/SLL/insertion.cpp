
void insertAtHead(Node* &head,Node* &tail,int data) {
  Node* node = new Node(data);
  if(head == NULL) {
    head = node;
    tail = node;
    return;
  }
  
  node->next = head;
  head = node;
}

void insertAtTail(Node* &head,Node* &tail,int data) {
  Node* node = new Node(data);
  if(head == NULL) {
    head = node;
    tail = node;
    return;
  }
  
  tail->next = node;
  tail = node;
}



int getLength(Node* head) {
  int cnt = 0;
  Node* temp = head;
  while(temp != NULL) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

void insertAtPosition(Node* &head, int value,int pos,Node* &tail){
  
   if(pos == 1) {
     insertAtHead(head,tail,value);
   } else if(pos > getLength(head)) {
     insertAtTail(head,tail,value);
   } else {
     Node* curr = head;
     Node* prev = NULL;
     Node* node = new Node(value);
     while(pos != 1) {
       prev = curr;
       curr = curr->next;
       prev--;
     }
     prev->next = node;
     node->next = curr;
   }
}

