class Node {
  int data;
  Node next;


  Node(int data) {
    this.data = data;
    this.next = null;
  }

  Node(int data, Node next) {
    this.data  = data;
    this.next = next;
  }
}

public class Main {
  public static void main(String[] args) {
    Node node = new Node(20);
    Node  node2 = new Node(10);
    Node node3 = new Node(30);

    node2.next = node;
    node.next = node3;
    display(node2);
  }

  static void display(Node head) {
    Node temp = head;
    while(temp != null) {
      System.out.print(temp.data + "->");
      temp = temp.next;
    }
    System.out.println("END");
  }
}