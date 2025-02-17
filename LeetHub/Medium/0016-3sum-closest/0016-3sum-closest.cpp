class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ap = -40000000;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                if (abs(target - ap) > abs(target - sum)) ap = sum;
                if (sum > target) --r;
                else ++l;
            }
        }

        return ap;
    }
};