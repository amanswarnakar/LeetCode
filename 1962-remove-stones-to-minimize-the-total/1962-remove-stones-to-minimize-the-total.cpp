class Solution {
public:
    int minStoneSum(vector<int>& v, int k) {
      priority_queue<int> pq;
      for(auto &i: v) pq.push(i);
      while(k--){
        auto top = pq.top();
        if(top == 1) break;
        pq.pop();
        top = (top + 1) / 2;
        pq.push(top);
      }
      int ans = 0;
      while(!pq.empty()){
        ans += pq.top();
        pq.pop();
      }
      return ans;
    }
};