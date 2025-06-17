class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<char,int> mpp;

        int i = 0, j = 0;
        int ans = 1;

        for (int j = 0; j < n; ++j) {
            if(mpp.find(s[j]) != mpp.end()) {
                i = max(i, mpp[s[j]] + 1);
            }
            mpp[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
