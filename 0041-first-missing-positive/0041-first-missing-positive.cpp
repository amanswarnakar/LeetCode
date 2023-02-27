class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
      int n = v.size();
      vector<int> arr(n + 1, -1);
      for(int i = 0; i < n; i++){
        if(v[i] < 0 or v[i] > n)
          continue;
        arr[v[i]] = 1;
      }
      for(int i = 1; i < n + 1; i++){
        if(arr[i] == -1) return i;
      }
      return n + 1;
    }
};