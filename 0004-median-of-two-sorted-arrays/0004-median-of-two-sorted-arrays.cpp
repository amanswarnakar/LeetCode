class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
      vector<int> v(v1.begin(), v1.end());
      for(auto &i: v2) v.emplace_back(i);
      sort(v.begin(), v.end());
      int n = v.size();
      if(n % 2)
        return double(v[n / 2]);
      return double(v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
};