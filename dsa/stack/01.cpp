#include<bits/stdc++.h>
using namespace std;

class MyStack{
  int* arr;
  int top;
  int size;

  MyStack(int size){
    this->size = size;
    arr = new int(size);
    top = -1;
  }

  void push(int val){
    if(top == size) {
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top++;
    arr[top] = val;
  }
}