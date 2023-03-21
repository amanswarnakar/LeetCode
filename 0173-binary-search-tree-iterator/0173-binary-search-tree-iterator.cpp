/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int k;
  
    void inorder(TreeNode *node, vector<int> &v){
      if(!node) return;
      inorder(node->left, v);
      v.emplace_back(node->val);
      inorder(node->right, v);
    }
  
    BSTIterator(TreeNode* root) {
      v.resize(0);
      k = -1;
      inorder(root, v);
    }
    
    int next() {
      return v[++k];
    }
    
    bool hasNext() {
      return k == -1 or k < v.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */