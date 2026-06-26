[1480](https://leetcode.com/problems/running-sum-of-1d-array)
```
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
```

[485](https://leetcode.com/problems/max-consecutive-ones)
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                max_c = max(count, max_c);
            } else {
                count = 0;
            }
        }
        return max_c;
    }
};
```

[283](https://leetcode.com/problems/move-zeroes)
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0, fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=0){
                swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
    }
};
```

[167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                return {start + 1, end + 1};
            } else if ((numbers[start] + numbers[end]) > target) {
                end--;
            } else {
                start++;
            }
        }
        return {};
    }
};
```

[121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, buy = prices[0];

        for(int i = 1; i<prices.size(); i++){
            if(prices[i]<buy) buy = prices[i];
            else {
                int profit = prices[i]-buy;
                if(profit > maxProfit) maxProfit = profit; 
            }
        }

        return maxProfit;
    }
};
```

[26](https://leetcode.com/problems/remove-duplicates-from-sorted-array)
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                nums[++i]=nums[j];
            } else {
                j++;
            }
        }
        return i+1;
    }
};
```

[88](https://leetcode.com/problems/merge-sorted-array)
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;

        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
```

[75](https://leetcode.com/problems/sort-colors/description/)
<!-- DNF: Dutch National Flag -->
```
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 1)
                mid++;
            else if (arr[mid] == 0)
                swap(arr[low++], arr[mid++]);
            else
                swap(arr[mid], arr[high--]);
        }
    }
};
```

[34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
```
class Solution {
public:
    int firstOccurence(vector<int> &nums, int  target){
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid]==target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }

        return ans;
    }

    int lastOccurence(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid]==target) {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurence(nums, target), lastOccurence(nums, target)};
    }
};
```