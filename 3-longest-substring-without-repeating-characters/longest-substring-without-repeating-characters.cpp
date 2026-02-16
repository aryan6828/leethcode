class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            count[s[r]]++;
            while (count[s[r]] > 1) {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};