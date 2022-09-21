class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
      // Brute Force    TC - O(N^2) - TLE;
      
      // int n = v.size(), m = q.size();
      // vector<int> ans;
      // for(int i = 0; i < m; i++){
      //   v[q[i][1]] += q[i][0];
      //   int temp = 0;
      //   for(int j = 0; j < n; j++){
      //     if(!(v[j] & 1)) temp += v[j];
      //   }
      //   ans.push_back(temp);
      // }
      // return ans;
      
      int n = v.size(), m = q.size();
      vector<int> ans;
      int esum = 0;
      for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0) esum += v[i];
      }
      for(int i = 0; i < m; i++){
        int val = q[i][0], idx = q[i][1];        
        if(v[idx] % 2 == 0) esum -= v[idx];
        v[idx] += val;
        if(v[idx] % 2 == 0) esum += v[idx];
        ans.push_back(esum);
      }
      return ans;
    }
};