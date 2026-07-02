[01](https://www.geeksforgeeks.org/problems/reverse-an-array/1)

```
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int first = 0;
        int last = arr.size()-1;
        
        while(first<last){
            swap(arr[first], arr[last]);
            first++;
            last--;
        }
    }
};
```

[02](https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1)

```
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i]>arr[i+1]) return false; 
        }
        return true;
    }
};
```

[03](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1)
```
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
};
```

[04](https://www.geeksforgeeks.org/problems/second-largest3735/1)
```
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = INT_MIN;
        int s_largest = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>largest){
                s_largest = largest;
                largest = arr[i];
            } else if (arr[i] > s_largest && arr[i] < largest){
                s_largest = arr[i];
            }
        }
        
        return s_largest == INT_MIN ? -1 : s_largest ;
    }
};
```

[05](https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1)
```
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            int need = target - arr[i];
            int j = i+1, k = arr.size()-1;
            while(j<k){
                int sum = arr[j]+arr[k];
                if(sum == need) return true;
                else if(sum<need) j++;
                else k--;
            }
        }
        return false;
    }
};
```

[06](https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/)
```
class Solution {
	public:
	bool pairInSortedRotated(vector<int>& arr, int target) {
		// code here
		int pivot = 0;
		int n = arr.size();
		
		for (int i = 1; i<n; i++) {
			if (arr[i - 1]>arr[i]) {
				pivot = i;
				break;
			}
		}
		
		int i = pivot, j = (pivot - 1 + n) % n ;
		
		while (i != j) {
			int sum = arr[i]+arr[j];
			if (sum == target)
				return true;
			else if (sum<target)
				i = (i + 1)%n;
			else
				j = (j - 1 + n)%n;
		}
		
		return false;
	}
};
```

[07](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/)
```
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int low = 0, high = arr.size()-1;
        int ans = -1;
        
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid]==x){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid]<x){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
```

[08](https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1)
```
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        vector<bool> seen (256, false);
        string res = "";
        
        for(char ch : s){
            if(!seen[ch]){
                res+=ch;
                seen[ch] = true;
            }
        }
        return res;
    }
};
```

[09](https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/)
```
class Solution {
  public:
    string firstRepChar(string s) {
        vector<bool> seen (256, false);
        for(char ch : s){
            if(seen[ch]){
                return {ch};
            }
            seen[ch] = true;
        }
        return "-1";
    }
};
```

[10](https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/)
```
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        
        for(int right = 0; right < arr.size(); right++){
            sum+=arr[right];
            while(sum>x){
                minLength = min (minLength, right-left+1);
                sum-=arr[left++];
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
```