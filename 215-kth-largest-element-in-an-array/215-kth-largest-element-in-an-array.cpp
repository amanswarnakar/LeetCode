class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> pq;
      for(auto i : nums){
        pq.push(i);
      }
      while(k-- > 1){
        pq.pop();
      }
      return pq.top();
    }
};