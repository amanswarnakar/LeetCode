class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
      int n = v.size(), maxi = 0, maxSum = INT_MIN, minSum = INT_MAX, mini = 0, sum = 0;
      for(auto &i: v){
        maxi = max(i, maxi + i);
        maxSum = max(maxSum, maxi);
        mini = min(i, mini + i);
        minSum = min(minSum, mini);
        sum += i;
      }
      return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};