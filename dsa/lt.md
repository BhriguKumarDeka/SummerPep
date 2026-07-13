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

[169](https://leetcode.com/problems/majority-element/)
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (vote > 0) {
                if (nums[i] == candidate)
                    vote++;
                else vote--;
            } else {
                candidate = nums[i];
                vote = 1;
            }
        }

        return candidate;
    }
};
```

[242](https://leetcode.com/problems/valid-anagram/)
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int arr[26] = {0};

        for(char ch : s){
            arr[ch -'a']++;
        }

        for(char ch : t){
            arr[ch -'a']--;
            if(arr[ch -'a'] < 0) return false;
        }

        return true;
    }
};
```

[680](https://leetcode.com/problems/valid-palindrome-ii/)
```
class Solution {
public:
    bool palindromeHelper(string &s, int left, int right){
        while(left<right){
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
      int l = 0;
      int r = s.length()-1;

      while(l < r){
        if(s[l]==s[r]){
            l++;
            r--;
        } else {
            return palindromeHelper(s, l+1, r) || palindromeHelper(s, l, r-1); 
        }
      } 
      return true; 
    }
};
```

[392](https://leetcode.com/problems/is-subsequence/)
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.length();
    }
};
```

[33](https://leetcode.com/problems/search-in-rotated-array)
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[l] <= nums[mid]) {
                // left side is sorted
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                // right side is sorted
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
        return -1;
    }
};
```

[1456](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
```
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int count = 0;

        for (int i = 0; i < k; i++)
            if (isVowel(s[i]))
                count++;

        int ans = count;

        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i]))
                count++;
            if (isVowel(s[i - k]))
                count--;
            ans = max(ans, count);
        }

        return ans;
    }
};
```

[876](https://leetcode.com/problems/middle-of-the-linked-list/)
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!= NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
```

[206](https://leetcode.com/reverse-linked-list/)
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;

        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
};
```

[234](https://leetcode.com/problems/palindrome-linked-list/)
```
class Solution {
public:
    ListNode* reverseLL(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* findMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* revHead = reverseLL(mid);

        ListNode* temp1 = head;
        ListNode* temp2 = revHead;

        while(temp2!=NULL){
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};
```

[141](https://leetcode.com/problems/linked-list-cycle/)
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }

        return false;
    }
};
```

[724](https://leetcode.com/problems/find-pivot-index/)
```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;

        for(int i=0; i<nums.size(); i++){
            if( lsum == (total - lsum - nums[i])) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};
```

[643](https://leetcode.com/problems/maximum-average-subarray-i/)
```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowsum = 0;
        for(int i = 0; i<k; i++)
            windowsum+=nums[i];

        int maxsum = windowsum;

        for(int i = k; i<nums.size(); i++){
            windowsum+=nums[i];
            windowsum-=nums[i-k];
            maxsum = max(maxsum, windowsum);
        }

        return double(maxsum)/k;
    }
};
```

[328](https://leetcode.com/problems/odd-even-linked-list/)
```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
```

[19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        // if(head->next == NULL) retur 

        //move t2 ahead by n nodes
        for(int i=0; i<n; i++){
            t2 = t2->next;
        }

        if(t2 == NULL) return head->next;

        while(t2 != NULL && t2->next!=NULL){
            t1 = t1->next;
            t2 = t2->next;
        }

        ListNode* temp = t1->next;
        t1->next = temp->next;
        delete temp;

        return head;
    }
};
```

[86](https://leetcode.com/problems/partition-list/)
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead = new ListNode(-200);
        ListNode* rightHead = new ListNode(-200);

        ListNode* left = leftHead;
        ListNode* right = rightHead;

        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                left->next = temp;
                left = left->next;
            }
            else {
                right->next = temp;
                right = right->next;
            }

            temp = temp->next;
        }

        left->next = rightHead->next;
        right->next = NULL;
        // delete left;
        // delete right;

        return leftHead->next;
    }
};
```

[160](https://leetcode.com/problems/intersection-of-two-linked-lists/)
```
class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        int lenDiff = abs(lenA - lenB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if(lenB > lenA){
            while(lenDiff--){
                tempB = tempB->next;
            }
        } else {
            while(lenDiff--){
                tempA = tempA->next;
            }
        }

        while(tempA!=NULL || tempB !=NULL){
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
```

[146](https://leetcode.com/problems/lru-cache/)
```
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };
    unordered_map<int, Node*> cache;
    int cap;
    Node* tail;
    Node* head;

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* left = node->prev;
        Node* right = node->next;

        left->next = right;
        right->prev = left;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }

        Node* node = cache[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            node->val = value;

            moveToFront(node);
            return;
        }

        if(cache.size() == cap){
            Node* node = tail->prev;
            cache.erase(node->key);

            removeNode(node);
            delete node;
        }

        Node* node = new Node(key, value);
        cache[key] = node;

        addToFront(node);
    }
};
```

[]()
```
```