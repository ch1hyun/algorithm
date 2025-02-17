class Solution {
public:
    int bs(vector<int> &tmp, int target) {
        int l = 0, r = tmp.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (tmp[mid] == target) return mid;
            else if (tmp[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff >= nums.size()) indexDiff = nums.size() - 1;
        
        vector<int> tmp;
        tmp.assign(nums.begin(), nums.begin() + indexDiff);
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size() - 1; ++i) {
            if (tmp[i + 1] - tmp[i] <= valueDiff) return true;
        }

        for (int i = indexDiff; i < nums.size(); ++i) {
            int addIdx = bs(tmp, nums[i]);
            tmp.insert(tmp.begin() + addIdx, nums[i]);
            
            if (addIdx != tmp.size() - 1 && tmp[addIdx + 1] - tmp[addIdx] <= valueDiff) return true;
            if (addIdx > 0 && tmp[addIdx] - tmp[addIdx - 1] <= valueDiff) return true;

            int removeIdx = bs(tmp, nums[i - indexDiff]);
            tmp.erase(tmp.begin() + removeIdx);
        }

        return false;
    }
};