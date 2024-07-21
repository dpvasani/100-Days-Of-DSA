class Solution {
public:
  // Brutal force approach
  // Linear Work -> TC -> 0(n^2)
  // Two Pointer Approch
  int findPairs(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int i = 0, j = 1;
    // Two Pointer Approach
    while (j < nums.size()) {
      int diff = nums[j] - nums[i];
      if (diff == k) {
        ans.insert({nums[i], nums[j]});
        ++i;
        ++j;
      } else if (diff > k) {
        i++;
      } else {
        j++;
      }
      if (i == j)
        j++;
    }

    // Binary Search
    // a[i] - a[j] = k
    // a[i] + k = a[j]
    
    return ans.size();
  }
};

// Binary Search Method

class Solution {
public:
    int bs(vector<int>& nums, int start, int x) {
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == x) {
                return mid;
            } else if (x > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (bs(nums, i + 1, nums[i] + k) != -1) {
                ans.insert({nums[i], nums[i] + k});
            }
        }
        return ans.size();
    }
};
