class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        long long ans = 0;
        int mini = -1, maxi = -1, l = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] < minK || v[i] > maxK)
                l = i;
            if (v[i] == minK) 
                mini = i;
            if (v[i] == maxK)
                maxi = i;
            ans += max(0, min(maxi, mini) - l);
        }
        return ans;
    }
};