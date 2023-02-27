class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
      // Constant Space Solution
      
      int n = v.size();
      for(int i = 0; i < n; i++){
        while(v[i] > 0 and v[i] <= n and v[i] != v[v[i] - 1]){
          swap(v[i], v[v[i] - 1]);
        }
      }
      for(int i = 0; i < n; i++){
        if(v[i] != i + 1) return i + 1;
      }
      return n + 1;
      
      
      // Extra Space Solution
      
      // int n = v.size();
      // vector<int> arr(n + 1, -1);
      // for(int i = 0; i < n; i++){
      //   if(v[i] < 0 or v[i] > n)
      //     continue;
      //   arr[v[i]] = 1;
      // }
      // for(int i = 1; i < n + 1; i++){
      //   if(arr[i] == -1) return i;
      // }
      // return n + 1;
    }
};