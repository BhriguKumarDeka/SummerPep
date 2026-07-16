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

[11](https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/)
```
class Solution {
  public:
    // Function to delete middle element of a stack.
    void del(stack<int>& s, int count, int mid){
        if(count == mid){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        del(s, count+1, mid);
        s.push(temp);
    }
    
    void deleteMid(stack<int>& s) {
        // code here..
        if(s.empty()) return;
        
        int mid = s.size()/2 + 1;
        del(s, 1, mid);
        
    }
};
```

[12](https://www.geeksforgeeks.org/problems/stack-using-queue/1)
```
class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        int n = q.size();
        q.push(x);
        
        for(int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(!q.empty())
        q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()) return -1;
        return q.front();
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
```

[13](https://www.geeksforgeeks.org/problems/queue-reversal/)
```
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if(q.empty()) return;
        
        int val = q.front();
        q.pop();
        reverseQueue(q);
        q.push(val);
    }
};
```
[14](http://geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/)
```
class Solution {
  public:
    void reverse(queue<int> &q, int k){
        if(k == 0) return;
        int temp = q.front();
        q.pop();
        reverse(q, k-1);
        q.push(temp);
  }
  
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(k>q.size()) return q;
        reverse(q,k);
        int c = n-k;
        
        while(c--){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
    
    // queue<int>reverseFirstK(queue<int>q, int k){
    //     stack<int> st;
    //     if(k>q.size())return q;
        
    //     for(int i=0; i<k; i++){
    //         st.push(q.front());
    //         q.pop();
    //     }
        
    //     while(!st.empty()){
    //         q.push(st.top());
    //         st.pop();
    //     }
        
    //     for(int i = 0; i<q.size()-k; i++ ){
    //         q.push(q.front());
    //         q.pop();
    //     }
    //     return q;
    // }
};
```

[15](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/)
```
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int> st;
        // if(q.empty()) return;
        int n = q.size()/2;
        
        //1. push first half of queue to stack
        // q = 3 1 | st = 4 2
        for(int i = 0; i<n; i++){
            st.push(q.front());
            q.pop();
        }
        
        //2. push the stack elements to queue
        // q = 3 1 4 2 | st = 0
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        //3. dequeue first half and enqueue in the same queue
        // q = 4 2 3 1 | st = 0
        for(int i =0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
        
        //4. push the first half of queue to stack again
        // q = 3 1 | st = 2 4
        for(int i =0; i<n; i++){
            st.push(q.front());
            q.pop();
        }
        
        //5. Interleave the elements from queue and stack
        // q = 2 3 4 1
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
```
[16](https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/)
```
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector <int> res(n);
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() <= arr[i]) st.pop(); 
            
            if(st.empty()){
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};
```

[17](https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/)
```
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        return 1 + (countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
    }
};
```

[18](https://www.geeksforgeeks.org/problems/sum-of-binary-tree)
```
/* Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root == nullptr) return 0;
        
        int ls = sumBT(root->left);
        int rs = sumBT(root->right);
        
        return root->data + ls + rs;
    }
};
```