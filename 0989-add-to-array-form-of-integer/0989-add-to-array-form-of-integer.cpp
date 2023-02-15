class Solution {
public:
    vector<int> addToArrayForm(vector<int>& v, int k) {
      reverse(v.begin(), v.end());
      int carry = 0, i = 0;
      while(i < v.size()){
        v[i] += k;
        k = v[i] / 10;
        v[i] %= 10;
        i++;
      }
      while(k){
        v.emplace_back(k % 10);
        k /= 10;
      }
      reverse(v.begin(), v.end());
      return v;
    }
};