#include<bits/stdc++.h>
using namespace std;

// void printNum( int n){
//   if(n==0) return;
//   printNum(n-1);
//   cout<<n<<"\n";
// }

// int factorial(int n){
//   if(n==0 || n==1) return 1;
//   return n*factorial(n-1);
// }

// int fibonacci(int n){
//   if(n==1) return 1;
//   if(n==0) return 0;
//   return fibonacci(n-1)+fibonacci(n-2);
// }

// bool linearSearch(int arr[], int size, int key){
//   if(size==0) return false;
//   if(arr[0]== key) return true;
//   else 
//   return linearSearch(arr+1, size-1, key);
// }

bool binarySearch(vector<int> v, int low, int high, int key){
  if(low>high) return false;
  int mid = (low + high )/ 2;
  if(v[mid] == key) return true;
  else if (v[mid] > key) return binarySearch(v, low, mid-1, key);
  else return binarySearch(v, mid+1, high, key);
}

int main(){
  // printNum(10);
  // cout<<factorial(5);
  // cout<<"\n";
  // cout<<factorial(10);
  // cout<<fibonacci(2);
  // cout<<fibonacci(3);
  // cout<<fibonacci(4);
  // cout<<fibonacci(5);

  // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  // int size = 8;
  // int key = 50;
  // cout<<linearSearch(arr, size, key);

  vector<int> v = {3, 5,7, 9, 11, 13, 15};
  int key = 10;
  cout<<binarySearch(v, 0, v.size()-1, key);
  cout<<binarySearch(v, 0, v.size()-1, 13);
}