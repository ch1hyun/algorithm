class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long check = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (check > 1000000000) break;
                    int sum = (int) check;
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    } else if (sum > target) --r;
                    else ++l;
                }
            }
        }

        return ans;
    }
};