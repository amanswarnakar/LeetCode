/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> um;
    Node* cloneGraph(Node* node) {
      if(!node) return NULL;
      if(um.find(node) != um.end()) return um[node];
      um[node] = new Node(node->val, {});
      for(auto &adj: node->neighbors){
        um[node]->neighbors.emplace_back(cloneGraph(adj));
      }
      return um[node];
    }
};