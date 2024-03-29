/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    ListNode *node;
    TreeNode *helper(int l, int r){
      if(l > r) return NULL;
      TreeNode *left, *right;
      int mid = l + (r - l) / 2;
      left = helper(l, mid - 1);
      
      TreeNode *root = new TreeNode(node->val);
      root->left = left;
      node = node->next;
      
      right = helper(mid + 1, r);
      root->right = right;
      
      return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
      node = head;
      int n = 0;
      ListNode *temp = head;
      while(temp){
        temp = temp->next;
        n++;
      }
      return helper(0, n - 1);
    }
  /*
    TreeNode *helper(vector<int> &v, int l, int r){
      if(l > r) return NULL;
      TreeNode *root = new TreeNode(0);
      int mid = l + (r - l) / 2;
      root->val = v[mid];
      root->left = helper(v, l, mid - 1);
      root->right = helper(v, mid + 1, r);
      return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
      vector<int> v;
      while(head){
        v.emplace_back(head->val);
        head = head->next;
      }
      TreeNode *root = helper(v, 0, v.size() - 1);
      return root;
    }
  */
};