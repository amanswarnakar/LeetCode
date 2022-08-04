/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
      // HashMap Solution TC - O(2N)  SC - O(N)
      map<Node*, Node*> mp;
      Node *dh = new Node(0);
      dh->next = head;
      while(head){
        Node *temp = new Node(head->val);
        mp[head] = temp;
        head = head->next;
      }
      head = dh->next;
      while(head){
        mp[head]->next = mp[head->next];
        mp[head]->random = mp[head->random];
        head = head->next;
      }
      return mp[dh->next];
    }
};