/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool checkAllSame(vector<vector<int>> &v, int r, int c, int n){
      for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
          if(v[i][j] != v[r][c]) return false;
        }
      }
      return true;
    }
    Node *helper(vector<vector<int>> &v, int i, int j, int n){
      if(checkAllSame(v, i, j, n))
        return new Node(v[i][j], true);
      Node *ret = new Node(true, false);
      ret->topLeft = helper(v, i, j, n / 2);
      ret->topRight = helper(v, i, j + n / 2, n / 2);
      ret->bottomLeft = helper(v, i + n / 2, j, n / 2);
      ret->bottomRight = helper(v, i + n / 2, j + n / 2, n / 2);
      return ret;      
    }
    Node* construct(vector<vector<int>>& grid) {
      return helper(grid, 0, 0, grid.size());
    }
};