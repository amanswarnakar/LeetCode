class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
      unordered_map<int, int> um;
      for(auto &pos: forbidden){
        um[pos]++;
      }
      queue<pair<int, pair<int, bool>>> q;
      q.push({0, {0, true}});
      while(!q.empty()){
        auto node = q.front();
        int currPos = node.first, ans = node.second.first;
        bool canGoBackwards = node.second.second;
        q.pop();
        if(currPos == x) return ans;
        if(um.find(currPos) != um.end()) continue;
        um[currPos]++;
        int forward = currPos + a, backward = currPos - b;
        if(canGoBackwards and backward >= 0){
          q.push({backward, {ans + 1, false}});
        }
        if(forward <= 2000 + a + b){    // 1 <= a, b, forbidden[i] <= 2000
          q.push({forward, {ans + 1, true}});
        }
      }
      return -1;
    }
};