class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      priority_queue<int> pq;
      int mini = INT_MAX, ans = INT_MAX;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 1){
          nums[i] *= 2;
        }
        pq.push(nums[i]);
        mini = min(mini, nums[i]);
      }
      while(true){
        int maxi = pq.top();
        pq.pop();
        ans = min(ans, maxi - mini);
        if(maxi % 2 == 1) break;
        maxi = maxi / 2;
        mini = min(mini, maxi);
        pq.push(maxi);
      }
      return ans;
    }
};