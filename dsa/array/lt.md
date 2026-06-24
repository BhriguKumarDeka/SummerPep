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

[]()
```

```