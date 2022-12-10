class Solution {
public:
    int findMin(vector<int>& v) {
      for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1]) return v[i + 1];
      }
      return v[0];
    }
};