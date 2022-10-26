class Solution {
public:
    bool isValid(int pos, int n){
      return (pos >= 0 and pos < n);
    }
    bool canReach(vector<int>& arr, int s) {
      int n = arr.size();
      vector<bool> vis(n);
      queue<int> q;
      q.push(s);
      while(!q.empty()){
        int currPos = q.front();
        if(arr[currPos] == 0) return true;
        vis[currPos] = true;
        q.pop();
        int forwardJump = currPos + arr[currPos], backwardJump = currPos - arr[currPos];
        if(isValid(forwardJump, n) and !vis[forwardJump]){
          q.emplace(forwardJump);
        }
        if(isValid(backwardJump, n) and !vis[backwardJump]){
          q.emplace(backwardJump);
        }
      }
      return false;
    }
};