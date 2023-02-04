class Node {
public:
  int val;
  Node *next;
  Node(): val(0), next(NULL) {}
  Node(int val): val(val), next(NULL) {}
  Node(int val, Node *next): val(val), next(next) {}
};

class MyLinkedList {
  Node *head;
  int sz;
public:
  MyLinkedList() {
    head = new Node();
    sz = 0;
  }

  int get(int index) {
    if(index < 0 or index >= sz) return -1;
    Node *curr = this->head->next;
    while(index--){
      curr = curr->next;
    }
    return curr->val;
  }

  void addAtHead(int val) {
    this->addAtIndex(0, val);
  }

  void addAtTail(int val) {
    this->addAtIndex(this->sz, val);
  }

  void addAtIndex(int index, int val) {
    if(index < 0 or index > sz) return;
    Node *curr = this->head;
    while(index--){
      curr = curr->next;
    }
    curr->next = new Node(val, curr->next);
    this->sz++;
  }

  void deleteAtIndex(int index) {
    if(index < 0 or index >= sz) return;
    Node *curr = this->head;
    while(index--){
      curr = curr->next;
    }
    Node *delNode = new Node();
    delNode = curr->next;
    curr->next = curr->next->next;
    delete(delNode);
    this->sz--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */