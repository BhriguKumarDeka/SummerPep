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




