/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, vector<int> &ans){
      if(!node) return;
      for(auto &child: node->children){
        dfs(child, ans);
      }
      ans.emplace_back(node->val);
    }
    vector<int> postorder(Node* root) {
      vector<int> ans;
      dfs(root, ans);
      return ans;
    }
};