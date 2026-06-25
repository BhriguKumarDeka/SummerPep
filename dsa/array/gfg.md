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


