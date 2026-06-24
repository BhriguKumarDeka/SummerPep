#include<bits/stdc++.h>
using namespace std;

int searchAndModifyKey(vector<int> arr, int key){
  for(int i=0; i<arr.size(); i++){
    if(arr[i]==key && key>10){
      return 2*key;
    } else if(arr[i]==key && key<10){
      return (0.5)*key;
    }
  }
  return -1;
}

//binary search
int binarySearch(vector<int> arr, int key, int size){
  int low = 0, high = size-1;

  while(low<high){
    int mid = (low+high)/2;

    if(arr[mid]==key) return mid;
    else if (arr[mid]<key) low = mid + 1;
    else high = mid - 1;
  }

  return -1;
}

int main(){
  vector<int> v = {3, 5, 1, 12, 36, 32, 4};
  // cout<<searchAndModifyKey(v, 12);

  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout<<binarySearch(arr, 4, v.size());
  return 0;
}  