#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int start) {
        if(start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);          // choice
            backtrack(nums, ans, start + 1);     // explore
            swap(nums[start], nums[i]);          // undo (backtrack)
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        return ans;
    }
};
