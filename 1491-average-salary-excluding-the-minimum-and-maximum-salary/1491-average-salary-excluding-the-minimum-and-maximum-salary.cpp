class Solution {
public:
    double average(vector<int>& v) {
      int n = v.size();
      int mx = *max_element(v.begin(), v.end()), mn = *min_element(v.begin(), v.end()), sum = accumulate(v.begin(), v.end(), 0);
      return double(sum - mx - mn) / (n - 2);
    }
};