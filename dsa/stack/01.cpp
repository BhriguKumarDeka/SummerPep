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

  void pop(){
    if(top==-1){
      cout<<"Stack underflow"<<endl;
      return;
    }
    top--;
  }

  bool isEmpty(){
    return (top == -1);
  }

  int peek(){
    return arr[top];
  }

  int size(){
    return top+1;
  }

};

int main(){
  
}